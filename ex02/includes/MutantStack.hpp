/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:24:36 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/20 10:43:18 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() {}
  MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack() {}

  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  iterator begin() { return this->c.begin(); };
  iterator end() { return this->c.end(); };
  const_iterator begin() const { return this->c.begin(); };
  const_iterator end() const { return this->c.end(); };
};

template <typename T, typename Container>
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other) {
  if (this != &other)
    std::stack<T, Container>::operator=(other);
  return *this;
}
