/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:33:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/29 15:24:51 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleState.hpp"

#include <ncursesw/ncurses.h>

#include "Game.hpp"

PuzzleState::PuzzleState(const Game &game)
	: _levels(game.getLevels()),
	  _activeLevel(_levels.at(0)),
	  _wordlist(game.getWordlist()),
	  _stateRequest(0) {
	_hilit.fill(false);
}

PuzzleState::~PuzzleState() {}

void PuzzleState::handleInput() {
	int key = getch();
	if (_input.size() < 11 && std::isalpha(key)) {
		if (std::islower(key))
			key = std::toupper(key);
		_input.push_back(static_cast<char>(key));
	} else if (_input.size() && key == KEY_BACKSPACE) {
		_input.erase(std::prev(_input.end()));
	}
}

void PuzzleState::update(float deltaTime) {
	(void)deltaTime;
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
	std::string remaining =
		"Moves Left: " + std::to_string(_activeLevel.getRemainingMoves());

	renderer.drawText(remaining.c_str(), UI_X + 1, UI_Y - 2);
	renderer.setDrawColor(6, 0);
	for (uint32_t y = 0; y < PUZZLE_H; y++) {
		for (uint32_t x = 0; x < PUZZLE_W; x++) {
			if (_activeLevel.getCell(x, y) != ' ') {
				renderer.drawText("[ ]", UI_X + 1 + x * 3, UI_Y + 1 + y);
				renderer.setDrawColor(7, 0);
				renderer.drawChar(_activeLevel.getCell(x, y), UI_X + 2 + x * 3,
								  UI_Y + 1 + y);
				renderer.setDrawColor(6, 0);
			} else
				renderer.drawText("   ", UI_X + 1 + x * 3, UI_Y + 1 + y);
		}
	}
	renderer.resetDrawColor();
}

std::deque<Tree<PuzzleState::Coord>> PuzzleState::findMatches() const {
	std::deque<Tree<PuzzleState::Coord>> matches;
	if (_input.empty())
		return (matches);
	for (uint32_t y = 0; y < PUZZLE_H; ++y) {
		for (uint32_t x = 0; x < PUZZLE_W; ++x) {
			if (_activeLevel.getCell(x, y) != _input.at(0))
				continue;
			Tree<Coord> tree({x, y});
			matches.push_back(tree);
			// start tracking usedLetters for each tree
			std::array<bool, PUZZLE_AREA> usedLetters;
			for (bool &b : usedLetters)
				b = false;
			matchRecur(x + 1, y, matches.back(), 1, usedLetters);
			matchRecur(x - 1, y, matches.back(), 1, usedLetters);
			matchRecur(x, y + 1, matches.back(), 1, usedLetters);
			matchRecur(x, y - 1, matches.back(), 1, usedLetters);
			if (matches.back().getChildren().empty() && _input.length() > 1)
				matches.erase(matches.end() - 1);
		}
	}
	return (matches);
}

uint32_t PuzzleState::matchRecur(
	uint32_t x, uint32_t y, Tree<Coord> &tree, uint32_t idx,
	std::array<bool, PUZZLE_AREA> usedLetters) const {
	if (idx == _input.length())
		return (1);
	if (x > PUZZLE_W || y > PUZZLE_H)
		return (0);
	if (usedLetters[x + y * PUZZLE_W])
		return (0);
	if (_activeLevel.getCell(x, y) != _input.at(idx))
		return (0);
	usedLetters[x + y * PUZZLE_W] = true;
	Coord	 coord = {x, y};
	auto	&next = tree.addChild(coord);
	uint32_t sum = 0;
	sum += matchRecur(x + 1, y, next, idx + 1, usedLetters);
	sum += matchRecur(x - 1, y, next, idx + 1, usedLetters);
	sum += matchRecur(x, y + 1, next, idx + 1, usedLetters);
	sum += matchRecur(x, y - 1, next, idx + 1, usedLetters);
	if (sum == 0)
		tree.deleteLastChild();
	return (sum);
}

int32_t PuzzleState::getStateRequest() const {
	return (_stateRequest);
}
