/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMenu.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:36:27 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 14:41:08 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMENU_HPP
#define AMENU_HPP

#include <vector>

#include "AState.hpp"
#include "MenuItem.hpp"
#include "Renderer.hpp"

class AMenu : public AState {
	protected:
		std::string_view	  _textBlock;
		std::vector<MenuItem> _menuItems;
		uint32_t			  _selectedId;

	public:
		AMenu(std::string_view textBlock, std::vector<MenuItem> menuItems);
		virtual ~AMenu() = default;
		void handleInput() override final;
		void update(double deltaTime) override final {
			(void)deltaTime;
		};
		void render(Renderer &renderer) const override final;
};

#endif
