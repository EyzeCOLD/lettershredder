/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:33:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 16:11:59 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleState.hpp"

PuzzleState::PuzzleState() : _stateRequest(0) {}

PuzzleState::~PuzzleState() {}

void PuzzleState::handleInput() {}

void PuzzleState::update(float deltaTime) {
	(void)deltaTime;
}

void PuzzleState::render(Renderer &renderer) {
	renderer.drawText("PUZZLE", 0, 0);
}

int32_t PuzzleState::getStateRequest() const {
	return (_stateRequest);
}
