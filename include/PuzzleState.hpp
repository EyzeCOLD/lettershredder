/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:58:47 by juaho             #+#    #+#             */
/*   Updated: 2025/12/29 15:24:44 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLESTATE_HPP
#define PUZZLESTATE_HPP
#include <array>
#include <deque>

#include "AGamestate.hpp"
#include "Level.hpp"
#include "Tree.hpp"
#include "Wordlist.hpp"

class Game;

class PuzzleState : public AGamestate {
	private:
		struct Coord {
				uint32_t x, y;
		};

		static constexpr uint32_t UI_X = 14;
		static constexpr uint32_t UI_Y = 3;

		std::string					  _input;
		std::deque<Level>			  _levels;
		std::array<bool, PUZZLE_AREA> _hilit;
		Level						  _activeLevel;
		const Wordlist				 &_wordlist;
		int32_t						  _stateRequest;

		void					drawPuzzleFrame(Renderer &renderer) const;
		void					drawLevel(Renderer &renderer) const;
		std::deque<Tree<Coord>> findMatches() const;
		uint32_t matchRecur(uint32_t x, uint32_t y, Tree<Coord> &tree,
							uint32_t					  idx,
							std::array<bool, PUZZLE_AREA> usedLetters) const;

	public:
		PuzzleState(const Game &game);
		~PuzzleState();
		void	handleInput();
		void	update(float deltaTime);
		void	render(Renderer &renderer) const;
		int32_t getStateRequest() const;
};

#endif
