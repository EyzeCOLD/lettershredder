/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LevelState.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:35:03 by juaho             #+#    #+#             */
/*   Updated: 2025/12/12 15:41:10 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP
#include <stack>

#include "Level.hpp"

class LevelState {
	private:
		std::stack<Level> _levelStates;

	public:
		LevelState();
		~LevelState() = default;
};

#endif
