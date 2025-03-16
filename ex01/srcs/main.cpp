/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:03:28 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/16 15:19:55 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <exception>
#include <iostream>

void testPDF() {
  std::cout << "============TESTPDF============" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void testError() {
  std::cout << "============TESTERROR============" << std::endl;
  Span sp = Span(3);
  sp.addNumber(10);
  sp.addNumber(20);
  sp.addNumber(30);
  try {
    sp.addNumber(40);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  Span sp2 = Span(1);
  sp2.addNumber(1);
  try {
    std::cout << sp2.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << sp2.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void testBigData() {
  std::cout << "============TESTBIGDATA============" << std::endl;
  std::vector<int> bigData;
  for (int i = 0; i < 10000; ++i)
    bigData.push_back(i * 2);

  Span bigSpan(10000);
  bigSpan.addNumbers(bigData.begin(), bigData.end());

  std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
  std::cout << "longest: " << bigSpan.longestSpan() << std::endl;
}

int main(void) {
  testPDF();
  testError();
  testBigData();
  return 0;
}
