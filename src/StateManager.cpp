/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StateManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:16:06 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:05:51 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StateManager.hpp"

#include "AState.hpp"
#include "Game.hpp"
#include "PauseMenu.hpp"
#include "PuzzleMode.hpp"
#include "PuzzleModeLevelSelect.hpp"
#include "PuzzleModeMenu.hpp"
#include "PuzzleWinMenu.hpp"
#include "StartMenu.hpp"

StateManager::StateManager() {
	_gameState.emplace(std::make_unique<StartMenu>());
}

StateManager::~StateManager() {}

AState &StateManager::currentState() {
	return (*_gameState.top());
}

void StateManager::handleInput() {
	currentState().handleInput();
}

void StateManager::update(float dt) {
	currentState().update(dt);
}

void StateManager::render(Renderer &render) {
	currentState().render(render);
}

void StateManager::handleStateRequests(const Game &game) {
	StateRequest stateRequest = currentState().extractStateRequest();
	switch (stateRequest.request) {
		case 1:
			while (hasState())
				_gameState.pop();
			break;
		case 2:
			_gameState.pop();
			pushState<PuzzleMode>(game, stateRequest.index);
			break;
		case 3:
			_gameState.pop();
			pushState<StartMenu>();
			break;
		case 4:
			pushState<PauseMenu>();
			break;
		case 5:
			_gameState.pop();
			break;
		case 6:
			_gameState.pop();
			pushState<PuzzleWinMenu>();
			break;
		case 7:
			_gameState.pop();
			pushState<PuzzleModeMenu>();
			break;
		case 8:
			_gameState.pop();
			pushState<PuzzleModeLevelSelect>(game);
		default:
			break;
	}
}

bool StateManager::hasState() const {
	return (not _gameState.empty());
}
