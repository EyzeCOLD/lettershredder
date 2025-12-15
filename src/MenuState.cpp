/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:33:25 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:06:40 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MenuState.hpp"

#include <ncurses.h>

#include <stdexcept>

MenuState::MenuState()
	: _currentMenu(&_mainMenu), _selectedId(0), _stateRequest(0) {
	_mainMenu.push_back(MenuItem("PUZZLE MODE", 2));
	_mainMenu.push_back(MenuItem("ENDLESS MODE", 0));
	_mainMenu.push_back(MenuItem("OPTIONS", 3));
	_mainMenu.push_back(MenuItem("QUIT", 1));

	_optionsMenu.push_back(MenuItem("BRIGHTNESS", 0));
	_optionsMenu.push_back(MenuItem("CONTRAST", 0));
	_optionsMenu.push_back(MenuItem("LANGUAGE", 0));
	_optionsMenu.push_back(MenuItem("MAIN MENU", 4));
}

void MenuState::handleInput() {
	if (_currentMenu->empty())
		throw(std::runtime_error("Empty menu"));
	switch (getch()) {
		case KEY_UP:
			_selectedId--;
			break;
		case KEY_DOWN:
			_selectedId++;
			break;
		case 10:
			// fallthrough
		case KEY_ENTER:
			_stateRequest = _currentMenu->at(_selectedId).activate();
			break;
		default:
			break;
	}
	_selectedId = (_selectedId + _currentMenu->size()) % _currentMenu->size();
}

void MenuState::update(float deltaTime) {
	(void)deltaTime;
	if (_stateRequest == 3 && _currentMenu == &_mainMenu) {
		_stateRequest = 0;
		_currentMenu = &_optionsMenu;
		_selectedId = 0;
	}
	if (_stateRequest == 4 && _currentMenu == &_optionsMenu) {
		_stateRequest = 0;
		_currentMenu = &_mainMenu;
		_selectedId = 0;
	}
}

void MenuState::render(Renderer &renderer) {
	renderer.setDrawColor(6, 0);
	renderer.drawText(
		"                          _          _   _\n"
		"                         | |        | | | |\n"
		"                         | |     ___| |_| |_ ___ _ __\n"
		"                         | |    / _ \\ __| __/ _ \\ '__|\n"
		"                         | |___|  __/ |_| ||  __/ |\n"
		"                         \\_____/\\___|\\__|\\__\\___|_|\n"
		"                    _____ _                  _     _\n"
		"                   /  ___| |                | |   | |\n"
		"                   \\ `--.| |__  _ __ ___  __| | __| | ___ _ __\n"
		"                    `--. \\ '_ \\| '__/ _ \\/ _` |/ _` |/ _ \\ '__|\n"
		"                   /\\__/ / | | | | |  __/ (_| | (_| |  __/ |\n"
		"                   \\____/|_| |_|_|  \\___|\\__,_|\\__,_|\\___|_|",
		0, 0);

	int32_t x = 33, y = 13;
	for (int32_t i = 0; (uint32_t)i < _currentMenu->size(); i++) {
		if (i == _selectedId)
			renderer.setDrawColor(0, 6);
		else
			renderer.setDrawColor(6, 0);
		renderer.drawText(" " + _currentMenu->at(i).getLabel() + " ", x,
						  y + i * 2);
	}
}

int32_t MenuState::getStateRequest() const {
	return (_stateRequest);
}
