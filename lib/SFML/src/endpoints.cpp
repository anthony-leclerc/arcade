/*
** endpoints.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/endpoints.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. avr. 05 18:16:19 2017 Anthony LECLERC
// Last update Sun Apr  9 07:03:38 2017 Sylvain Chaugny
*/

#include "SFMLContext.hpp"

namespace arcade {
  extern "C" void delete_point(api::IContext *context)
  {
    delete context;
  }

  extern "C" api::IContext *entry_point()
  {
    return new sfml::SFMLContext(1600, 960);
  }
}
