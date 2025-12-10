/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGamestate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:37:49 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 15:36:11 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMESTATE_HPP
#define AGAMESTATE_HPP
#include "Renderer.hpp"

class AGamestate {
	private:
		enum Type { MenuState, PuzzleState };

	public:
		AGamestate();
		virtual ~AGamestate() = 0;
		virtual void handleInput() = 0;
		virtual void update(float deltaTime) = 0;
		virtual void render(Renderer &renderer) = 0;
};

#endif
