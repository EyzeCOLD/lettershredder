/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMenu.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:57:50 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:01:01 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMenu.hpp"

#include <ncursesw/ncurses.h>

#include <stdexcept>

AMenu::AMenu(std::string_view textBlock, std::vector<MenuItem> menuItems)
	: _textBlock(textBlock), _menuItems(std::move(menuItems)) {}

void AMenu::handleInput() {
	if (_menuItems.empty())
		throw(std::runtime_error("Empty menu"));
	switch (getch()) {
		case KEY_UP:
			if (--_selectedId >= _menuItems.size())
				_selectedId = _menuItems.size() - 1;
			break;
		case KEY_DOWN:
			if (++_selectedId >= _menuItems.size())
				_selectedId = 0;
			break;
		case 10:
			// fallthrough
		case KEY_ENTER:
			AState::_stateRequest.request =
				_menuItems.at(_selectedId).activate();
			break;
		default:
			break;
	}
}

void AMenu::render(Renderer &renderer) const {
	renderer.setDrawColor(6, 0);
	renderer.drawText(_textBlock.data(), 0, 0);

	int32_t x = 33, y = 13;
	for (uint32_t i = 0; i < _menuItems.size(); ++i) {
		if (i == _selectedId)
			renderer.setDrawColor(0, 6);
		else
			renderer.setDrawColor(6, 0);
		renderer.drawText(" " + _menuItems.at(i).getLabel() + " ", x,
						  y + i * 2);
	}
}
