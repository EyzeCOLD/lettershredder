/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:41:06 by juaho             #+#    #+#             */
/*   Updated: 2025/12/30 12:35:39 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <vector>

template <class T>
class Tree {
	private:
		T					 _content;
		std::vector<Tree<T>> _children;

	public:
		Tree(T t) : _content(t) {};
		~Tree() = default;

		const T &getContent() const {
			return (_content);
		}

		T &getContent() {
			return (_content);
		}

		std::vector<Tree<T>> &getChildren() {
			return _children;
		}

		const std::vector<Tree<T>> &getChildren() const {
			return _children;
		}

		bool hasChildren() const {
			return (not _children.empty());
		}

		Tree<T> &addChild(const Tree<T> &tree) {
			_children.push_back(tree);
			return (_children.back());
		}

		void deleteLastChild() {
			if (_children.empty())
				return;
			_children.erase(_children.end() - 1);
		}
};

#endif
