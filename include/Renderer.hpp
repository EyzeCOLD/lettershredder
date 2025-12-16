/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:49:04 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 19:23:51 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <map>
#include <string>

class Renderer {
	private:
		std::map<std::pair<int32_t, int32_t>, int32_t> _colorPairCache;
		int32_t										   _currentColorPair;
		bool										   _initialized;

	public:
		Renderer();
		~Renderer();

		void init();
		void setDrawColor(int32_t foreground, int32_t background);
		void resetDrawColor();
		void drawText(const std::string &text, uint32_t x, uint32_t y) const;
		void drawChar(char c, uint32_t x, uint32_t y) const;
		void clearScreen() const;
		void render() const;
};

#endif
