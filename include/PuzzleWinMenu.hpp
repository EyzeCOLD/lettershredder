/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleWinMenu.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:42:54 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:10:58 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLEWINMENU_HPP
#define PUZZLEWINMENU_HPP

#include "AMenu.hpp"
#include "MenuItem.hpp"

class PuzzleWinMenu : public AMenu {
	private:
		static constexpr std::string_view _winScreenText =
			"\n\n\n\n\n"
			"                            [C][O][N][G][R][A][T][S]\n"
			"\n"
			"                        You have completed Puzzle Mode!\n"
			"\n"
			"                             Thank You for playing!";

	public:
		PuzzleWinMenu()
			: AMenu(_winScreenText,
					{{MenuItem("START MENU", 3)}, {MenuItem("QUIT", 1)}}) {}
		~PuzzleWinMenu() = default;
};

#endif
