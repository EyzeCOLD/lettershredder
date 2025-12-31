/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:54:28 by juaho             #+#    #+#             */
/*   Updated: 2025/12/31 15:20:44 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Level.hpp"

#include <fstream>

Level::Level() : _remainingMoves(0) {}

Level::Level(std::array<char, PUZZLE_AREA> grid, uint32_t moves)
	: _grid(grid), _remainingMoves(moves) {}

void Level::loadFromFile(const std::string &path) {
	std::ifstream file(path, std::ios::in);
	if (not file.is_open())
		throw(std::runtime_error("Level::loadFromFile(): open(): can't"));

	std::string line;
	std::getline(file, line);
	_remainingMoves = std::stoi(line);

	uint32_t y = 0;
	uint32_t x;
	while (true) {
		std::getline(file, line);
		if (file.fail())
			break;
		x = 0;
		for (char c : line) {
			if (c >= 'a' && c <= 'z') {
				setCell(std::toupper(c), x, y);
			} else if ((c < 'A' || c > 'Z') && c != ' ') {
				throw(std::runtime_error(
					"Level::loadFromFile(): non-alphabetic blocks"));
			}
			setCell(c, x, y);
			if (++x > PUZZLE_W)
				throw(
					std::runtime_error("Level::loadFromFile(): grid too wide"));
		}

		// pad with spaces
		while (x < PUZZLE_W) {
			setCell(' ', x, y);
			++x;
		}
		if (++y > PUZZLE_H)
			throw(std::runtime_error("Level::loadFromFile(): grid too high"));
	}

	while (y < PUZZLE_W) {
		x = 0;
		while (x < PUZZLE_W) {
			setCell(' ', x, y);
			++x;
		}
		++y;
	}
}

void Level::setRemainingMoves(uint32_t moves) {
	_remainingMoves = moves;
}

void Level::setCell(char c, uint32_t x, uint32_t y) {
	_grid[x + y * PUZZLE_W] = c;
}

const std::array<char, PUZZLE_AREA> &Level::getGrid() const {
	return (_grid);
}

char Level::getCell(uint32_t x, uint32_t y) const {
	return (_grid[x + y * PUZZLE_W]);
}

uint32_t Level::getRemainingMoves() const {
	return (_remainingMoves);
}

bool Level::hasFloatingBlocks() const {
	for (uint32_t col = 0; col < PUZZLE_W; ++col) {
		for (int32_t row = PUZZLE_H - 2; row > -1; --row) {
			if (getCell(col, row) != ' ' && getCell(col, row + 1) == ' ') {
				return (true);
			}
		}
	}
	return (false);
}
