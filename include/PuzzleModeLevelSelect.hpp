/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleModeLevelSelect.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:50:12 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 15:04:14 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLEMODELEVELSELECT
#define PUZZLEMODELEVELSELECT

#include "AState.hpp"
#include "Game.hpp"

class PuzzleModeLevelSelect : public AState {
	private:
		static constexpr uint32_t		  _levelsPerRow = 5;
		static constexpr std::string_view _textBlock =
			"\n\n\n\n"
			"                           PUZZLE MODE - LEVEL SELECT";
		const uint32_t _numberOfLevels;
		uint32_t	   _selectedId;

	public:
		PuzzleModeLevelSelect(const Game &game);
		~PuzzleModeLevelSelect() = default;

		void handleInput() override final;
		void update(double deltaTime) override final;
		void render(Renderer &renderer) const override final;
};

#endif
