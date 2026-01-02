/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGamestate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:37:49 by juaho             #+#    #+#             */
/*   Updated: 2025/12/15 15:37:45 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAMESTATE_HPP
#define AGAMESTATE_HPP
#include "Renderer.hpp"

class AGamestate {
	public:
		AGamestate() = default;
		virtual ~AGamestate() = default;
		virtual void	handleInput() = 0;
		virtual void	update(double deltaTime) = 0;
		virtual void	render(Renderer &renderer) const = 0;
		virtual int32_t getStateRequest() const = 0;
};

#endif
