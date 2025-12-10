/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordlist.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:01:25 by juaho             #+#    #+#             */
/*   Updated: 2025/12/10 12:12:23 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordlist.hpp"

#include <cstring>
#include <fstream>

Wordlist::Wordlist() {}

bool Wordlist::contains(const std::string word) const {
	return (_words.find(word) != _words.end());
}

void Wordlist::loadFile(const std::string& path) {
	std::ifstream file(path, std::ios::in);
	if (file.fail())
		throw(std::runtime_error("Wordlist::loadFile(): Couldn't open file '" +
								 path + "': " + strerror(errno)));

	std::string s;
	while (std::getline(file, s).good())
		_words.insert(s);
}
