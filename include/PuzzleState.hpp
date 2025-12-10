/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleState.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:58:47 by juaho             #+#    #+#             */
/*   Updated: 2025/12/08 12:00:34 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLESTATE_HPP
#define PUZZLESTATE_HPP
#include "AGamestate.hpp"

class PuzzleState : public AGamestate {
	private:
	public:
		PuzzleState();
		~PuzzleState();
		void handleInput();
		void update();
		void render();
};

#endif
