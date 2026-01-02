/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:23:40 by juaho             #+#    #+#             */
/*   Updated: 2025/12/31 15:49:37 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <ncursesw/ncurses.h>

#include <chrono>

Game::Game() {}

Game::~Game() {}

void Game::init() {
	_wordlist.loadFile("./wordlists/wordlist.txt");
	_levels = getPuzzles();
	_renderer.init();
}

void Game::run() {
	double dt = 0;
	double frameTime = _frameDuration;
	while (_stateManager.hasState()) {
		dt = deltaTime();
		_stateManager.handleInput();
		_stateManager.update(dt);

		frameTime += dt;
		if (frameTime >= _frameDuration) {
			frameTime -= _frameDuration;
			_renderer.clearScreen();
			_stateManager.render(_renderer);
			_renderer.render();
		}

		_stateManager.handleStateRequests(*this);
	}
}

const std::deque<Level> &Game::getLevels() const {
	return (_levels);
}

const Wordlist &Game::getWordlist() const {
	return (_wordlist);
}

double Game::deltaTime() {
	// first call returns 0
	static std::chrono::time_point<std::chrono::steady_clock> last =
		std::chrono::steady_clock::now();

	const auto now = std::chrono::steady_clock::now();

	std::chrono::duration<double> diff = now - last;
	last = now;
	return (diff.count());
}
