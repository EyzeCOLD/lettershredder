/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:18:13 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 18:11:22 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

#include <ncurses.h>

#include <cstring>
#include <stdexcept>

Renderer::Renderer() : _currentColorPair(0) {}

Renderer::~Renderer() {
	endwin();
}

void Renderer::init() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	start_color();
}

void Renderer::setDrawColor(int32_t foreground, int32_t background) {
	std::pair<int32_t, int32_t> colorPair(foreground, background);

	attroff(COLOR_PAIR(_currentColorPair));
	auto cached = _colorPairCache.find(colorPair);
	if (cached != _colorPairCache.end()) {
		_currentColorPair = cached->second;
	} else {
		_currentColorPair = _colorPairCache.size() + 1;
		if (_currentColorPair >= COLOR_PAIRS)
			_currentColorPair = 0;
		else {
			_colorPairCache.insert({colorPair, _currentColorPair});
			init_pair(_currentColorPair, foreground, background);
		}
	}
	attron(COLOR_PAIR(_currentColorPair));
}

void Renderer::drawText(const std::string &text, uint32_t x, uint32_t y) const {
	if (mvaddstr(y, x, text.c_str()) == ERR)
		throw(std::runtime_error(strerror(errno)));
}

void Renderer::clearScreen() const {
	clear();
}

void Renderer::render() const {
	refresh();
}
