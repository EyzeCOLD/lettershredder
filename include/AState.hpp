/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AState.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:37:49 by juaho             #+#    #+#             */
/*   Updated: 2026/01/13 16:04:55 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTATE_HPP
#define ASTATE_HPP
#include "Renderer.hpp"

struct StateRequest {
		int32_t request;
		int32_t index;
};

class AState {
	protected:
		StateRequest _stateRequest = {0, 0};

	public:
		AState() = default;
		virtual ~AState() = default;
		virtual void handleInput() = 0;
		virtual void update(double deltaTime) = 0;
		virtual void render(Renderer &renderer) const = 0;
		StateRequest extractStateRequest() {
			StateRequest ret = _stateRequest;
			_stateRequest.request = 0;
			_stateRequest.index = 0;
			return (ret);
		};
};

#endif
