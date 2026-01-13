/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PauseMenu.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:19:40 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 13:49:17 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP

#include "AMenu.hpp"
#include "MenuItem.hpp"

class PauseMenu : public AMenu {
	private:
		static constexpr std::string_view _pauseMenuText =
			"\n\n\n\n"
			"                               ===== PAUSED =====\n"
			"\n"
			"                               A-Z - input letters\n"
			"                               ENTER - make a move\n"
			"                               SPACE - undo (PuzzleMode)\n"
			"\n"
			"                               ==================\n";

	public:
		PauseMenu()
			: AMenu(_pauseMenuText, {{MenuItem("CONTINUE", 5)},
									 {MenuItem("START MENU", 3)},
									 {MenuItem("QUIT", 1)}}) {}
		~PauseMenu() = default;
};

#endif
