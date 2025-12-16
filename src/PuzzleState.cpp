/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:33:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:11:59 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleState.hpp"

PuzzleState::PuzzleState() : _stateRequest(0) {
	_level.loadFromFile("./levels/puzzle1.txt");
}

PuzzleState::~PuzzleState() {}

void PuzzleState::handleInput() {}

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
	renderer.resetDrawColor();
}

void PuzzleState::drawLevel(Renderer &renderer) const {
	std::string remaining =
		"Moves Left: " + std::to_string(_level.getRemainingMoves());

	renderer.drawText(remaining.c_str(), UI_X + 1, UI_Y - 2);
	renderer.setDrawColor(6, 0);
	for (uint32_t y = 0; y < PUZZLE_H; y++) {
		for (uint32_t x = 0; x < PUZZLE_W; x++) {
			if (_level.getCell(x, y) != ' ') {
				renderer.drawText("[ ]", UI_X + 1 + x * 3, UI_Y + 1 + y);
				renderer.setDrawColor(7, 0);
				renderer.drawChar(_level.getCell(x, y), UI_X + 2 + x * 3,
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
