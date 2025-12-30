/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:33:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 16:02:01 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleState.hpp"

#include <ncursesw/ncurses.h>

#include "Game.hpp"

PuzzleState::PuzzleState(const Game &game)
	: _levels(game.getLevels()),
	  _levelRunner(_levels.front()),
	  _wordlist(game.getWordlist()),
	  _stateRequest(0) {}

PuzzleState::~PuzzleState() {}

void PuzzleState::handleInput() {
	int key = getch();
	if (_input.size() < 11 && std::isalpha(key)) {
		if (std::islower(key))
			key = std::toupper(key);
		_input.push_back(static_cast<char>(key));
	} else if (_input.size() && key == KEY_BACKSPACE) {
		_input.erase(std::prev(_input.end()));
	} else if (key == KEY_ENTER || key == 10) {
		_levelRunner.destroyMatches();
		_input.clear();
	} else if (key == '`') {
		_levelRunner.undoMove();
		_input.clear();
	} else {
		return;
	}

	_levelRunner.updateMatches(_input);
	_levelRunner.hilightMatches();
}

void PuzzleState::update(float deltaTime) {
	(void)deltaTime;
	_levelRunner.applyGravity();
}

void PuzzleState::render(Renderer &renderer) const {
	drawPuzzleFrame(renderer);
	drawLevel(renderer);
}

void PuzzleState::drawPuzzleFrame(Renderer &renderer) const {
	renderer.setDrawColor(3, 0);
	std::string topLine = "╔";
	std::string bottomLine = "╚";
	for (uint32_t i = 0; i < PUZZLE_W; i++) {
		topLine.append("═══");
		bottomLine.append("═══");
	}
	topLine.append("╗");
	bottomLine.append("╝");
	renderer.drawText(topLine, UI_X, UI_Y);
	for (uint32_t i = 0; i < PUZZLE_H; i++) {
		renderer.drawText("║", UI_X, UI_Y + 1 + i);
		renderer.drawText("║", UI_X + 1 + PUZZLE_W * 3, UI_Y + 1 + i);
	}
	renderer.drawText(bottomLine, UI_X, UI_Y + 1 + PUZZLE_H);

	renderer.drawText("Input: ", UI_X, UI_Y + 3 + PUZZLE_H);
	renderer.setDrawColor(7, 0);
	renderer.drawText(_input, UI_X + 7, UI_Y + 3 + PUZZLE_H);
	renderer.resetDrawColor();
}

void PuzzleState::drawLevel(Renderer &renderer) const {
	Level level = _levelRunner.getCurrentState();

	std::string remaining =
		"Moves Left: " + std::to_string(level.getRemainingMoves());

	renderer.drawText(remaining.c_str(), UI_X + 1, UI_Y - 2);
	renderer.setDrawColor(6, 0);
	for (uint32_t y = 0; y < PUZZLE_H; y++) {
		for (uint32_t x = 0; x < PUZZLE_W; x++) {
			if (level.getCell(x, y) != ' ') {
				renderer.drawText("[ ]", UI_X + 1 + x * 3, UI_Y + 1 + y);
				if (_levelRunner.isHilit(x, y))
					renderer.setDrawColor(6, 0);
				else
					renderer.setDrawColor(7, 0);
				renderer.drawChar(level.getCell(x, y), UI_X + 2 + x * 3,
								  UI_Y + 1 + y);
				renderer.setDrawColor(6, 0);
			} else
				renderer.drawText("   ", UI_X + 1 + x * 3, UI_Y + 1 + y);
		}
	}
	renderer.resetDrawColor();
}

int32_t PuzzleState::getStateRequest() const {
	return (_stateRequest);
}
