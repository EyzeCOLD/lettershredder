/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:16:06 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:09:00 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StateManager.hpp"

#include "AGamestate.hpp"
#include "MenuState.hpp"
#include "PuzzleState.hpp"

StateManager::StateManager() : _gameState(new MenuState()) {}

StateManager::~StateManager() {
	if (_gameState)
		delete _gameState;
}

void StateManager::loadState(AGamestate *newState) {
	delete _gameState;
	_gameState = newState;
}

void StateManager::handleInput() {
	_gameState->handleInput();
}

void StateManager::update(float dt) {
	_gameState->update(dt);
}

void StateManager::render(Renderer &render) {
	_gameState->render(render);
}

void StateManager::checkStateRequests() {
	switch (_gameState->getStateRequest()) {
		case 1:
			delete _gameState;
			_gameState = nullptr;
			break;
		case 2:
			loadState(new PuzzleState());
		default:
			break;
	}
}

bool StateManager::hasState() const {
	return (_gameState != nullptr);
}
