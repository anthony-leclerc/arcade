/*
** MouliInterface.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/MouliInterface.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. avr. 09 08:54:56 2017 Anthony LECLERC
** Last update dim. avr. 09 08:54:56 2017 Anthony LECLERC
*/

#include <iostream>
#include "MouliInterface.hpp"

bool arcade::MouliInterface::getCommand()
{
  if (std::cin.read(reinterpret_cast<char *>(&_currCommand), sizeof(uint16_t)))
  {
    makeCommand(static_cast<CommandType>(_currCommand));
    return true;
  }
  return false;
}

void arcade::MouliInterface::makeCommand(arcade::CommandType command)
{
  switch (command)
  {
    case CommandType::WHERE_AM_I:
      convertPosition(game.getPlayer().getPosition());
      writeData(*_me);
      break;
    case CommandType::GET_MAP:
      convertMap(game.getMap().getMap());
      writeData(*_map);
      break;
    case CommandType::GO_UP:

      game.getPlayer().setDirection(centipede::Direction::UP);
      break;
    case CommandType::GO_LEFT:

      game.getPlayer().setDirection(centipede::Direction::LEFT);
      break;
    case CommandType::GO_RIGHT:

      game.getPlayer().setDirection(centipede::Direction::RIGHT);
      break;
    case CommandType::GO_DOWN:

      game.getPlayer().setDirection(centipede::Direction::DOWN);
      break;
    case CommandType::SHOOT:

      game.getPlayer().shot();
      break;
    case CommandType::PLAY:

      game.update();
      break;
    default:
      break;
  }
}

arcade::MouliInterface::MouliInterface() :
    game(),
    _me(0)
{
  _me = new WhereAmI[sizeof(WhereAmI) + sizeof(arcade::Position)];

  game.gameDataInit(20, 30);
  _me->type = CommandType::WHERE_AM_I;
  _me->lenght = 1;
  _map = new GetMap[sizeof(GetMap) + game.getMap().getMap().size()];
  _map->type = CommandType ::GET_MAP;
  _map->height = static_cast<uint16_t>(game.getMap().getHeight());
  _map->width = static_cast<uint16_t>(game.getMap().getWidth());
}

void arcade::MouliInterface::convertPosition(arcade::utl::Position const &pos)
{
  _me->position->x = static_cast<uint16_t>(pos.x);
  _me->position->y = static_cast<uint16_t>(pos.y);
}

void arcade::MouliInterface::convertMap(std::vector<TileType> const &m)
{
  std::copy(m.begin(), m.end(), &_map->tile[0]);
}

arcade::MouliInterface::~MouliInterface()
{
  delete[] _me;
  delete[] _map;
}
