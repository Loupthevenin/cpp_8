/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:30:12 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/16 15:03:17 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int maxValue;
  std::vector<int> vec;

public:
  Span(unsigned int maxValue);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int value);
  void addNumbers(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);
  int shortestSpan() const;
  int longestSpan() const;
};
