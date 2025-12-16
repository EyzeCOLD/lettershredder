/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:42 by juaho             #+#    #+#             */
/*   Updated: 2025/12/11 12:16:20 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
#define LEVEL_HPP
#define PUZZLE_H 10
#define PUZZLE_W 10
#include <string>

class Level {
	private:
		char	 _grid[PUZZLE_H][PUZZLE_W];
		uint32_t _remainingMoves;

	public:
		Level();
		~Level() = default;
		void	 loadFromFile(const std::string &path);
		char	 getCell(uint32_t x, uint32_t y) const;
		uint32_t getRemainingMoves() const;
};

#endif
