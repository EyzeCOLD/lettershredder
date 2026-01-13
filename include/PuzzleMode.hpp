/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleMode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:58:47 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 14:48:55 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLEMODE_HPP
#define PUZZLEMODE_HPP
#include <deque>

#include "AState.hpp"
#include "Level.hpp"
#include "LevelRunner.hpp"
#include "Wordlist.hpp"

class Game;

class PuzzleMode : public AState {
	private:
		static constexpr uint32_t UI_X = 14;
		static constexpr uint32_t UI_Y = 3;

		std::string		  _input;
		std::string		  _feedback;
		std::deque<Level> _levels;
		uint32_t		  _currentLevel;
		LevelRunner		  _levelRunner;
		const Wordlist	 &_wordlist;
		const double	  _gravityTick = 0.2;

		void drawPuzzleFrame(Renderer &renderer) const;
		void drawLevel(Renderer &renderer) const;

	public:
		PuzzleMode(const Game &game, uint32_t currentLevel);
		~PuzzleMode();
		void handleInput();
		void update(double deltaTime);
		void render(Renderer &renderer) const;
};

#endif
