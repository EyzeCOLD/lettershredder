/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:33:24 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 17:22:17 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP
#include "Renderer.hpp"
#include "StateManager.hpp"

class Game {
	private:
		StateManager _stateManager;
		Renderer	 _renderer;

	public:
		Game();
		~Game();
		void run();
};

#endif
