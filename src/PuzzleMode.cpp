/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleMode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:33:42 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:09:37 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleMode.hpp"

#include <ncursesw/ncurses.h>

#include "Game.hpp"

PuzzleMode::PuzzleMode(const Game &game, uint32_t currentLevel)
	: _levels(game.getLevels()),
	  _currentLevel(currentLevel),
	  _levelRunner(_levels.at(currentLevel)),
	  _wordlist(game.getWordlist()) {}

PuzzleMode::~PuzzleMode() {}

void PuzzleMode::handleInput() {
	int key = getch();

	// ESC
	if (key == 27) {
		_stateRequest.request = 4;
		return;
	}

	// Level Complete
	if (_levelRunner.isClear()) {
		if (key == KEY_ENTER || key == 10) {
			if (_currentLevel + 1 == _levels.size())
				_stateRequest.request = 6;
			else {
				_levelRunner.loadLevel(_levels.at(++_currentLevel));
				_feedback.clear();
				key = 0;
			}
		} else {
			return;
		}
	}
	// Out of moves
	else if (_levelRunner.outOfMoves()) {
		// ENTER
		if (key == KEY_ENTER || key == 10) {
			_levelRunner.loadLevel(_levels.at(_currentLevel));
			_feedback.clear();
			key = 0;
			// Undo
		} else if (key == ' ') {
			_levelRunner.undoMove();
			_input.clear();
			_feedback.clear();
		} else {
			return;
		}
	}
	// The usual
	else {
		_levelRunner.updateMatches(_input);
		_levelRunner.hilightMatches();

		// Letter input
		if (_input.size() < 11 && std::isalpha(key)) {
			if (std::islower(key))
				key = std::toupper(key);
			_input.push_back(static_cast<char>(key));
			_feedback.clear();
			// BACKSPACE
		} else if (_input.size() && key == KEY_BACKSPACE) {
			_input.erase(std::prev(_input.end()));
			_feedback.clear();
			// ENTER
		} else if (key == KEY_ENTER || key == 10) {
			if (_levelRunner.getMatchAmount() == 0)
				_feedback = "'" + _input + "' not found on the board";
			else if (_wordlist.contains(_input)) {
				_levelRunner.destroyMatches();
				if (_levelRunner.isClear())
					_feedback = "Level complete! Press ENTER to continue...";
				else if (_levelRunner.outOfMoves())
					_feedback = "OUT OF MOVES, press ENTER to retry...";
				else
					_feedback = "'" + _input + "' found!";
				_input.clear();
			} else
				_feedback = "'" + _input + "' not found in the wordlist.";
			// Undo
		} else if (key == ' ') {
			_levelRunner.undoMove();
			_input.clear();
			_feedback.clear();
		} else {
			return;
		}
	}
}

void PuzzleMode::update(double deltaTime) {
	static double accum;
	if ((accum += deltaTime) < _gravityTick)
		return;
	else
		accum -= _gravityTick;
	if (not _levelRunner.isClear()) {
		_levelRunner.applyGravity();
	}
}

void PuzzleMode::render(Renderer &renderer) const {
	drawPuzzleFrame(renderer);
	drawLevel(renderer);
}

void PuzzleMode::drawPuzzleFrame(Renderer &renderer) const {
	renderer.setDrawColor(3, 0);
	renderer.drawBox(UI_X, UI_Y, PUZZLE_W * 3, PUZZLE_H);

	renderer.drawText(_feedback, UI_X, UI_Y + 2 + PUZZLE_H);
	renderer.drawText("Input: ", UI_X, UI_Y + 3 + PUZZLE_H);
	renderer.setDrawColor(7, 0);
	renderer.drawText(_input, UI_X + 7, UI_Y + 3 + PUZZLE_H);
	renderer.resetDrawColor();
}

void PuzzleMode::drawLevel(Renderer &renderer) const {
	Level level = _levelRunner.getCurrentState();

	std::string current = "LEVEL " + std::to_string(_currentLevel + 1);
	std::string remaining =
		"Moves Left: " + std::to_string(level.getRemainingMoves());

	renderer.drawText(current.c_str(), UI_X + 1, UI_Y - 3);
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
