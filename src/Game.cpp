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

Game::Game() {}

Game::~Game() {}

void Game::init() {
	_wordlist.loadFile("./wordlists/wordlist.txt");
	_levels = getPuzzles();
	_renderer.init();
}

void Game::run() {
	while (_stateManager.hasState()) {
		_stateManager.handleInput();
		// TODO make a clock
		_stateManager.update(1);
		_renderer.clearScreen();
		_stateManager.render(_renderer);
		_renderer.render();
		_stateManager.handleStateRequests(*this);
		napms(20);
	}
}

const std::deque<Level> &Game::getLevels() const {
	return (_levels);
}

const Wordlist &Game::getWordlist() const {
	return (_wordlist);
}
