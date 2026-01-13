/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StartMenu.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:42:31 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 14:54:11 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARTMENU_HPP
#define STARTMENU_HPP

#include "AMenu.hpp"
#include "MenuItem.hpp"

class StartMenu : public AMenu {
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
		StartMenu()
			: AMenu(_logo, {{MenuItem("PUZZLE MODE", 7)},
							{MenuItem("ENDLESS MODE", 0)},
							{MenuItem("QUIT", 1)}}) {}
		~StartMenu() = default;
};

#endif
