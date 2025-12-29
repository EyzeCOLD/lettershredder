/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:33:24 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 15:05:23 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP
#include <deque>

#include "Level.hpp"
#include "Renderer.hpp"
#include "StateManager.hpp"
#include "Wordlist.hpp"

class Game {
	private:
		StateManager	  _stateManager;
		Renderer		  _renderer;
		std::deque<Level> _levels;
		Wordlist		  _wordlist;

	public:
		Game();
		~Game();
		void					 init();
		void					 run();
		const std::deque<Level> &getLevels() const;
		const Wordlist			&getWordlist() const;
};

#endif
