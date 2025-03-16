/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:14:20 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/16 14:27:16 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void) {
  std::vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);

  try {
    std::vector<int>::iterator it = easyfind(arr, 5);
    std::cout << "Found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::vector<int>::iterator it = easyfind(arr, 6);
    std::cout << "Found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);

  try {
    std::list<int>::iterator it = easyfind(lst, 10);
    std::cout << "Found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::list<int>::iterator it = easyfind(lst, 41);
    std::cout << "Found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
