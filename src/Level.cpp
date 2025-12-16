/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:54:28 by juaho             #+#    #+#             */
/*   Updated: 2025/12/11 12:41:24 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Level.hpp"

#include <fstream>

Level::Level() {}

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
				_grid[y][x] = std::toupper(c);
			} else if ((c < 'A' || c > 'Z') && c != ' ') {
				throw(std::runtime_error(
					"Level::loadFromFile(): non-alphabetic blocks"));
			}
			_grid[y][x] = c;
			if (++x > PUZZLE_W)
				throw(
					std::runtime_error("Level::loadFromFile(): grid too wide"));
		}

		// pad with spaces
		while (x < PUZZLE_W) {
			_grid[y][x] = ' ';
			++x;
		}
		if (++y > PUZZLE_H)
			throw(std::runtime_error("Level::loadFromFile(): grid too high"));
	}

	while (y < PUZZLE_W) {
		x = 0;
		while (x < PUZZLE_W) {
			_grid[y][x] = ' ';
			++x;
		}
		++y;
	}
}

char Level::getCell(uint32_t x, uint32_t y) const {
	return (_grid[y][x]);
}

uint32_t Level::getRemainingMoves() const {
	return (_remainingMoves);
}
