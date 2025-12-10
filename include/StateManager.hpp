/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 14:47:33 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include "AGamestate.hpp"

class StateManager {
	private:
		AGamestate *_gameState;

	public:
		StateManager();
		~StateManager();
		void handleInput();
		void update(float deltaTime);
		void render(Renderer &renderer);
};

#endif
