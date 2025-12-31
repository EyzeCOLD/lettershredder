/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LevelRunner.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:11:25 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 15:56:38 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVELRUNNER_HPP
#define LEVELRUNNER_HPP
#include <deque>

#include "Level.hpp"
#include "Tree.hpp"

class LevelRunner {
	private:
		struct Coord {
			public:
				uint32_t x, y;

				bool operator==(const Coord &other) {
					return (x == other.x && y == other.y);
				}
		};

		std::deque<Level>			  _levelHistory;
		std::array<bool, PUZZLE_AREA> _hilit;
		std::deque<Tree<Coord>>		  _matches;
		bool						  _clear;

		uint32_t updateMatchesRecur(Coord c, Tree<Coord> &tree,
									const std::string &str, uint32_t index,
									std::array<bool, PUZZLE_AREA> &usedChars);
		void	 hilightRecur(Tree<Coord> &tree);
		char	&getCharAtCoord(const Coord &c, Level &level);

	public:
		LevelRunner(const Level &level);
		~LevelRunner() = default;

		const Level &getCurrentState() const;
		uint32_t	 getMatchAmount() const;
		bool		 isClear();
		bool		 isHilit(uint32_t x, uint32_t y) const;
		uint32_t	 getHistorySize() const {
			return (_levelHistory.size());
		}

		void loadLevel(const Level &level);
		void updateMatches(const std::string &str);
		void hilightMatches();
		void destroyMatches();
		void applyGravity();
		void undoMove();
};

#endif
