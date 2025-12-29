/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:08:53 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include "AGamestate.hpp"

class Game;

class StateManager {
	private:
		AGamestate *_gameState;

		void loadState(AGamestate *newState);

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
