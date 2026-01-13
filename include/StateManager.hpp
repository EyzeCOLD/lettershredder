/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:42 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:04:16 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include <memory>
#include <stack>

#include "AState.hpp"

class Game;

class StateManager {
	private:
		std::stack<std::unique_ptr<AState>> _gameState;

		template <class StateType>
		void pushState() {
			static_assert(std::is_base_of<AState, StateType>::value,
						  "StateType must implement AState");
			_gameState.emplace(std::make_unique<StateType>());
		}

		template <class StateType>
		void pushState(const Game &game) {
			static_assert(std::is_base_of<AState, StateType>::value,
						  "StateType must implement AState");
			_gameState.emplace(std::make_unique<StateType>(game));
		}

		template <class StateType>
		void pushState(const Game &game, uint32_t startingLevel) {
			static_assert(std::is_base_of<AState, StateType>::value,
						  "StateType must implement AState");
			_gameState.emplace(
				std::make_unique<StateType>(game, startingLevel));
		}

		AState &currentState();

	public:
		StateManager();
		~StateManager();
		void handleInput();
		void update(float deltaTime);
		void render(Renderer &renderer);
		void handleStateRequests(const Game &game);
		bool hasState() const;
};

#endif
