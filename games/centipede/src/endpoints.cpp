/*
** endpoints.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/endpoints.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. avr. 08 00:37:31 2017 Anthony LECLERC
** Last update sam. avr. 08 00:37:31 2017 Anthony LECLERC
*/

#include "MouliInterface.hpp"

extern "C" arcade::api::AGame *entry_point()
{
  return new arcade::centipede::GameManager;
}

extern "C" void delete_point(arcade::api::AGame *g)
{
  delete g;
}

namespace arcade {
  extern "C" void Play()
  {
    MouliInterface mouli;
    while (mouli.getCommand());
  }
}