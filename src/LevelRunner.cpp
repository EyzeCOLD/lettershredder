/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LevelRunner.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:21:48 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 16:01:21 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LevelRunner.hpp"

#include <stdexcept>

LevelRunner::LevelRunner(const Level &level) {
	_levelHistory.push_back(level);
}

const Level &LevelRunner::getCurrentState() const {
	if (!_levelHistory.size())
		throw(std::runtime_error(
			"LevelRunner::getCurrentState(): levelHistory is empty"));
	return (_levelHistory.back());
}

uint32_t LevelRunner::getMatchAmount() const {
	return (_matches.size());
}

bool LevelRunner::isClear() const {
	const Level &level = getCurrentState();
	for (char c : level.getGrid())
		if (c != ' ')
			return (false);
	return (true);
}

bool LevelRunner::isHilit(uint32_t x, uint32_t y) const {
	return (_hilit[x + y * PUZZLE_W]);
}

void LevelRunner::loadLevel(const Level &level) {
	_levelHistory.clear();
	_levelHistory.push_back(level);
}

void LevelRunner::updateMatches(const std::string &str) {
	_matches.clear();
	if (str.empty())
		return;

	const Level &level = getCurrentState();

	std::array<bool, PUZZLE_AREA> usedChars;
	usedChars.fill(false);

	for (uint32_t y = 0; y < PUZZLE_H; ++y) {
		for (uint32_t x = 0; x < PUZZLE_W; ++x) {
			if (level.getCell(x, y) != str.at(0))
				continue;

			usedChars[x + y * PUZZLE_W] = true;
			_matches.push_back(Tree<Coord>({x, y}));

			if (str.length() == 1)
				continue;

			updateMatchesRecur({x + 1, y}, _matches.back(), str, 1, usedChars);
			updateMatchesRecur({x - 1, y}, _matches.back(), str, 1, usedChars);
			updateMatchesRecur({x, y + 1}, _matches.back(), str, 1, usedChars);
			updateMatchesRecur({x, y - 1}, _matches.back(), str, 1, usedChars);

			if (not _matches.back().hasChildren())
				_matches.erase(_matches.end() - 1);
		}
	}
}

uint32_t LevelRunner::updateMatchesRecur(
	Coord c, Tree<Coord> &tree, const std::string &str, uint32_t index,
	std::array<bool, PUZZLE_AREA> &usedChars) {
	if (index == str.length())
		return (1);
	if (c.x > PUZZLE_W || c.y > PUZZLE_H)
		return (0);
	if (usedChars[c.x + c.y * PUZZLE_W])
		return (0);
	if (getCurrentState().getCell(c.x, c.y) != str.at(index))
		return (0);
	usedChars[c.x + c.y * PUZZLE_W] = true;
	auto	&next = tree.addChild(c);
	uint32_t sum = 0;
	sum += updateMatchesRecur({c.x + 1, c.y}, next, str, index + 1, usedChars);
	sum += updateMatchesRecur({c.x - 1, c.y}, next, str, index + 1, usedChars);
	sum += updateMatchesRecur({c.x, c.y + 1}, next, str, index + 1, usedChars);
	sum += updateMatchesRecur({c.x, c.y - 1}, next, str, index + 1, usedChars);
	if (sum == 0)
		tree.deleteLastChild();
	return (sum);
}

void LevelRunner::hilightMatches() {
	_hilit.fill(false);

	if (_matches.empty())
		return;

	std::deque<Tree<Coord>> nodes;
	for (auto &tree : _matches)
		nodes.push_back(tree);

	while (not nodes.empty()) {
		const Tree<Coord> &front = nodes.front();
		for (auto &child : front.getChildren())
			nodes.push_back(child);
		_hilit[front.getContent().x + front.getContent().y * PUZZLE_W] = true;
		nodes.pop_front();
	}
}

void LevelRunner::destroyMatches() {
	if (_matches.empty())
		return;

	Level nextState(_levelHistory.back());
	nextState.setRemainingMoves(nextState.getRemainingMoves() - 1);

	std::deque<Tree<Coord>> nodes;
	for (auto &tree : _matches)
		nodes.push_back(tree);

	while (not nodes.empty()) {
		const Tree<Coord> &front = nodes.front();
		for (auto &child : front.getChildren())
			nodes.push_back(child);
		Coord c = front.getContent();
		nextState.setCell(' ', c.x, c.y);
		nodes.pop_front();
	}

	_levelHistory.push_back(nextState);
}

void LevelRunner::applyGravity() {
	if (not _levelHistory.back().hasFloatingBlocks())
		return;

	Level nextState(_levelHistory.back());

	for (uint32_t y = PUZZLE_H - 1; y != 0; --y) {
		for (uint32_t x = 0; x < PUZZLE_W; ++x) {
			if (nextState.getCell(x, y) == ' ' && nextState.getCell(x, y - 1)) {
				nextState.setCell(nextState.getCell(x, y - 1), x, y);
				nextState.setCell(' ', x, y - 1);
			}
		}
	}
	if (_levelHistory.back().hasFloatingBlocks())
		_levelHistory.pop_back();
	_levelHistory.push_back(nextState);
}

void LevelRunner::undoMove() {
	if (_levelHistory.size() > 1)
		_levelHistory.pop_back();
}
