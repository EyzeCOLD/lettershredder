/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleModeMenu.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:42:09 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 14:53:55 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLEMODEMENU_HPP
#define PUZZLEMODEMENU_HPP

#include "AMenu.hpp"
#include "MenuItem.hpp"

class PuzzleModeMenu : public AMenu {
	private:
		static constexpr std::string_view _logo =
			"                          _          _   _\n"
			"                         | |        | | | |\n"
			"                         | |     ___| |_| |_ ___ _ __\n"
			"                         | |    / _ \\ __| __/ _ \\ '__|\n"
			"                         | |___|  __/ |_| ||  __/ |\n"
			"                         \\_____/\\___|\\__|\\__\\___|_|\n"
			"                    _____ _                  _     _\n"
			"                   /  ___| |                | |   | |\n"
			"                   \\ `--.| |__  _ __ ___  __| | __| | ___ _ __\n"
			"                    `--. \\ '_ \\| '__/ _ \\/ _` |/ _` |/ _ \\ "
			"'__|\n"
			"                   /\\__/ / | | | | |  __/ (_| | (_| |  __/ |\n"
			"                   \\____/|_| |_|_|  \\___|\\__,_|\\__,_|\\___|_|";

	public:
		PuzzleModeMenu()
			: AMenu(_logo, {{MenuItem("NEW GAME", 2)},
							{MenuItem("LEVEL SELECT", 8)},
							{MenuItem("BACK", 3)}}) {}
		~PuzzleModeMenu() = default;
};
#endif
