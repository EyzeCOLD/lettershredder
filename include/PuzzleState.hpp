/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:58:47 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 14:54:52 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLESTATE_HPP
#define PUZZLESTATE_HPP
#include <deque>

#include "AGamestate.hpp"
#include "Level.hpp"
#include "LevelRunner.hpp"
#include "Wordlist.hpp"

class Game;

class PuzzleState : public AGamestate {
	private:
		static constexpr uint32_t UI_X = 14;
		static constexpr uint32_t UI_Y = 3;

		std::string		  _input;
		std::deque<Level> _levels;
		LevelRunner		  _levelRunner;
		const Wordlist	 &_wordlist;
		int32_t			  _stateRequest;

		void drawPuzzleFrame(Renderer &renderer) const;
		void drawLevel(Renderer &renderer) const;

	public:
		PuzzleState(const Game &game);
		~PuzzleState();
		void	handleInput();
		void	update(float deltaTime);
		void	render(Renderer &renderer) const;
		int32_t getStateRequest() const;
};

#endif
