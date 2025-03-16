/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:08:06 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/16 14:23:22 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>
#include <string>

class NotFoundException : public std::exception {
public:
  virtual const char *what() const throw() { return "Element not found"; }
};

template <typename T> typename T::iterator easyfind(T &container, int value) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw NotFoundException();
  return it;
}
