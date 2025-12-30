/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 15:33:02 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <array>
#include <string>

constexpr uint32_t PUZZLE_H = 10;
constexpr uint32_t PUZZLE_W = 10;
constexpr uint32_t PUZZLE_AREA = PUZZLE_H * PUZZLE_W;

class Level {
	private:
		std::array<char, PUZZLE_AREA> _grid;
		uint32_t					  _remainingMoves;

	public:
		Level();
		void loadFromFile(const std::string &path);
		void setCell(char c, uint32_t x, uint32_t y);
		void setRemainingMoves(uint32_t moves);

		const std::array<char, PUZZLE_AREA> &getGrid() const;
		char	 getCell(uint32_t x, uint32_t y) const;
		uint32_t getRemainingMoves() const;
		bool	 hasFloatingBlocks() const;
};

#endif
