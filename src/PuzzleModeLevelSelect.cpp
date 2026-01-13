/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleModeLevelSelect.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:57:59 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:07:45 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleModeLevelSelect.hpp"

#include <ncursesw/ncurses.h>

PuzzleModeLevelSelect::PuzzleModeLevelSelect(const Game &game)
	: _numberOfLevels(game.getLevels().size()) {}

void PuzzleModeLevelSelect::handleInput() {
	int key = getch();

	switch (key) {
		case KEY_ENTER:
			// fallthrough
		case 10:
			_stateRequest.request = 2;
			_stateRequest.index = _selectedId;
			break;
		case KEY_LEFT:
			if (--_selectedId >= _numberOfLevels)
				_selectedId = 0;
			break;
		case KEY_RIGHT:
			if (++_selectedId >= _numberOfLevels)
				_selectedId = _numberOfLevels - 1;
			break;
		case KEY_UP:
			if (_selectedId >= _levelsPerRow)
				_selectedId -= _levelsPerRow;
			break;
		case KEY_DOWN:
			if (_selectedId < _numberOfLevels - _levelsPerRow)
				_selectedId += _levelsPerRow;
			break;
		default:
			break;
	}
}

void PuzzleModeLevelSelect::update(double deltaTime) {
	(void)deltaTime;
}

void PuzzleModeLevelSelect::render(Renderer &renderer) const {
	renderer.setDrawColor(6, 0);
	renderer.drawText(_textBlock.data(), 0, 0);

	const uint32_t MenuPosX = 20;
	const uint32_t MenuPosY = 13;
	for (uint32_t i = 0; i < _numberOfLevels; ++i) {
		if (i == _selectedId)
			renderer.setDrawColor(0, 6);
		else
			renderer.setDrawColor(6, 0);
		renderer.drawText(std::to_string(i + 1) + " [x]",
						  MenuPosX + (i % _levelsPerRow) * 8,
						  MenuPosY + (i / _levelsPerRow) * 2);
	}
	renderer.resetDrawColor();
}
