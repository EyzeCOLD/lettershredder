/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:58:47 by juaho             #+#    #+#             */
/*   Updated: 2025/12/11 21:03:48 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLESTATE_HPP
#define PUZZLESTATE_HPP
#include "AGamestate.hpp"
#include "Level.hpp"

class PuzzleState : public AGamestate {
	private:
		Level	_level;
		int32_t _stateRequest;

	public:
		PuzzleState();
		~PuzzleState();
		void	handleInput();
		void	update(float deltaTime);
		void	render(Renderer &renderer);
		int32_t getStateRequest() const;
};

#endif
