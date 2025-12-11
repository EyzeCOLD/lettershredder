/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MenuItem.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:40:18 by juaho             #+#    #+#             */
/*   Updated: 2025/12/11 09:44:54 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENUITEM_HPP
#define MENUITEM_HPP
#include <string>

class MenuItem {
	private:
		const std::string _label;
		int32_t			  _onActivate;

	public:
		MenuItem(const std::string &label, int32_t onActivate)
			: _label(label), _onActivate(onActivate) {};

		~MenuItem() = default;

		const std::string &getLabel() const {
			return (_label);
		};

		int32_t activate() const {
			return (_onActivate);
		};
};

#endif
