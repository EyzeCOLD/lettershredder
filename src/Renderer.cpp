/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:18:13 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 14:10:14 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

#include <locale.h>
#include <ncurses.h>
#include <ncursesw/ncurses.h>

#include <cstring>
#include <stdexcept>

Renderer::Renderer() : _currentColorPair(0), _initialized(false) {}

Renderer::~Renderer() {
	endwin();
}

void Renderer::init() {
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	start_color();
	set_escdelay(0);
	_initialized = true;
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

void Renderer::resetDrawColor() {
	setDrawColor(7, 0);
}

void Renderer::drawText(const std::string &text, uint32_t x, uint32_t y) const {
	if (mvaddstr(y, x, text.c_str()) == ERR) {
		if (not _initialized)
			throw(std::runtime_error("Renderer not initialized"));
		else
			throw(std::runtime_error(strerror(errno)));
	}
}

void Renderer::drawChar(char c, uint32_t x, uint32_t y) const {
	if (mvaddch(y, x, c) == ERR) {
		if (not _initialized)
			throw(std::runtime_error("Renderer not initialized"));
		else
			throw(std::runtime_error(strerror(errno)));
	}
}

void Renderer::drawBox(uint32_t x, uint32_t y, uint32_t w, uint32_t h) const {
	std::string topLine = "╔";
	std::string bottomLine = "╚";
	for (uint32_t i = 0; i < w; i++) {
		topLine.append("═");
		bottomLine.append("═");
	}
	topLine.append("╗");
	bottomLine.append("╝");
	drawText(topLine, x, y);
	for (uint32_t i = 0; i < h; i++) {
		drawText("║", x, y + 1 + i);
		drawText("║", x + 1 + w, y + 1 + i);
	}
	drawText(bottomLine, x, y + 1 + h);
}

void Renderer::clearScreen() const {
	erase();
}

void Renderer::render() const {
	refresh();
}
