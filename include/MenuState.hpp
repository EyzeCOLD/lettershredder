/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:42:31 by juaho             #+#    #+#             */
/*   Updated: 2025/12/08 11:59:55 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include "AGamestate.hpp"

class MenuState : public AGamestate {
	private:
	public:
		MenuState();
		~MenuState();
		void handleInput();
		void update();
		void render();
};

#endif
