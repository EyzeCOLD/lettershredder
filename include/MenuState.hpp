/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:42:31 by juaho             #+#    #+#             */
/*   Updated: 2025/12/11 10:31:40 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include <vector>

#include "AGamestate.hpp"
#include "MenuItem.hpp"
#include "Renderer.hpp"

class MenuState : public AGamestate {
	private:
		std::vector<MenuItem> *_currentMenu;
		std::vector<MenuItem>  _mainMenu;
		std::vector<MenuItem>  _optionsMenu;
		int32_t				   _selectedId;
		int32_t				   _stateRequest;

	public:
		MenuState();
		~MenuState() = default;
		void	handleInput();
		void	update(float deltaTime);
		void	render(Renderer &renderer);
		int32_t getStateRequest() const;
};

#endif
