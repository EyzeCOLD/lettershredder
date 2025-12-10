/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordlist.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:56:46 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 12:11:32 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLIST_HPP
#define WORDLIST_HPP
#include <string>
#include <unordered_set>

class Wordlist {
	private:
		std::unordered_set<std::string> _words;

	public:
		Wordlist();
		~Wordlist() = default;
		bool contains(const std::string word) const;
		void loadFile(const std::string& path);
};

#endif
