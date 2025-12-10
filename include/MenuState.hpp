/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:42:31 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 20:20:28 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP
#include <vector>

#include "AGamestate.hpp"
#include "Renderer.hpp"

class MenuState : public AGamestate {
	private:
		std::vector<std::string> _menuItems;
		int32_t					 _selectedId;
		int32_t					 _stateRequest;

	public:
		MenuState();
		~MenuState() = default;
		void	handleInput();
		void	update(float deltaTime);
		void	render(Renderer &renderer);
		int32_t getStateRequest() const;
};

#endif
