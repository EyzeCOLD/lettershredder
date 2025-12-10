/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:33:25 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 20:23:36 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MenuState.hpp"

#include <ncurses.h>

#include <stdexcept>

MenuState::MenuState() : _selectedId(0), _stateRequest(0) {
	_menuItems.push_back("OPTION 1");
	_menuItems.push_back("OPTION 2");
	_menuItems.push_back("OPTION 3");
	_menuItems.push_back("QUIT");
}

void MenuState::handleInput() {
	if (_menuItems.empty())
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
			if (_menuItems.at(_selectedId) == "QUIT")
				_stateRequest = 1;
		default:
			break;
	}
	_selectedId = (_selectedId + _menuItems.size()) % _menuItems.size();
}

void MenuState::update(float deltaTime) {
	(void)deltaTime;
}

void MenuState::render(Renderer &renderer) {
	renderer.setDrawColor(6, 0);
	renderer.drawText("MENU 1", 5, 1);

	int32_t x = 3, y = 3;
	for (int32_t i = 0; (uint32_t)i < _menuItems.size(); i++) {
		if (i == _selectedId)
			renderer.setDrawColor(0, 6);
		else
			renderer.setDrawColor(6, 0);
		renderer.drawText(_menuItems[i], x, y + i * 2);
	}
}

int32_t MenuState::getStateRequest() const {
	return (_stateRequest);
}
