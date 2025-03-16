/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:30:03 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/16 20:19:12 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int maxValue) : maxValue(maxValue) {}

Span::Span(const Span &other) : maxValue(other.maxValue), vec(other.vec) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    maxValue = other.maxValue;
    vec = other.vec;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {

  if (vec.size() >= maxValue) {
    throw std::overflow_error("Cannot add more numbers, Span is full.");
  }
  vec.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
  if (vec.size() + std::distance(begin, end) > maxValue)
    throw std::overflow_error("Cannot add range, Span would exceed max size.");
  vec.insert(vec.end(), begin, end);
}

int Span::shortestSpan() const {
  if (vec.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate shortest span.");
  }
  std::vector<int> sortedVec = vec;
  std::sort(sortedVec.begin(), sortedVec.end());
  int minSpan = sortedVec[1] - sortedVec[0];
  for (size_t i = 1; i < sortedVec.size() - 1; ++i) {
    int span = sortedVec[i + 1] - sortedVec[i];
    if (span < minSpan)
      minSpan = span;
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (vec.size() < 2) {
    throw std::logic_error("Not enough numbers to calculate longest span.");
  }
  int minVal = *std::min_element(vec.begin(), vec.end());
  int maxVal = *std::max_element(vec.begin(), vec.end());
  return maxVal - minVal;
}

void addNumbers(Span &span, std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  while (begin != end) {
    span.addNumber(*begin);
    ++begin;
  }
}
