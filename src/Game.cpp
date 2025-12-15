/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:23:40 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:05:41 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <ncurses.h>

Game::Game() {}

Game::~Game() {}

void Game::init() {
	_wordlist.loadFile("./wordlists/wordlist.txt");
	_renderer.init();
	_level.loadFromFile("./levels/puzzle1.txt");
}

void Game::run() {
	while (_stateManager.hasState()) {
		_stateManager.handleInput();
		// TODO make a clock
		_stateManager.update(1);
		_renderer.clearScreen();
		_stateManager.render(_renderer);
		_renderer.render();
		_stateManager.checkStateRequests();
		napms(20);
	}
}
