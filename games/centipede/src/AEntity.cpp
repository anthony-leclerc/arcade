/*
** AEntity.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/AEntity.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 17:25:57 2017 Anthony LECLERC
** Last update jeu. avr. 06 17:25:57 2017 Anthony LECLERC
*/

#include "AEntity.hpp"

arcade::centipede::AEntity::AEntity(Grid const& map, api::IGraphic *g):
    _pos(),
    _size(),
    _map(map),
    _entityType(TileType::EMPTY),
    _graphic(g)
{}

void arcade::centipede::AEntity::setPosition(utl::Position const& pos)
{
  _pos.x = pos.x;
  _pos.y = pos.y;
}

arcade::centipede::AEntity::AEntity(Grid const& map, api::IGraphic *g, arcade::utl::Position const &pos) :
    _pos(pos),
    _size(1, 1),
    _map(map),
    _entityType(TileType::EMPTY),
    _graphic(g)
{}

arcade::centipede::AEntity::AEntity(Grid const& map, api::IGraphic *g, arcade::utl::Position const &pos,
				    arcade::utl::Dimensions size) :
_pos(pos),
_size(size),
_map(map),
_entityType(TileType::EMPTY),
_graphic(g)
{}

arcade::utl::Position const &arcade::centipede::AEntity::getPosition(void) const
{
  return _pos;
}

bool
arcade::centipede::AEntity::operator==(arcade::utl::Position const& pos) const
{
  return pos.x == _pos.x && pos.y == _pos.y;
}

bool
arcade::centipede::AEntity::operator!=(arcade::utl::Position const &pos) const
{
  return !(*this == pos);
}

bool arcade::centipede::AEntity::operator==(
    arcade::utl::Dimensions const &dims) const
{
  return dims.width == _size.width && dims.height == _size.height;
}

bool arcade::centipede::AEntity::operator!=(
    arcade::utl::Dimensions const &dims) const
{
  return !(*this == dims);
}

arcade::TileType arcade::centipede::AEntity::getType() const
{
  return _entityType;
}

void arcade::centipede::AEntity::setType(TileType type)
{
  _entityType = type;
}

void arcade::centipede::AEntity::resetGraphic(api::IGraphic *g)
{
  _graphic = g;
}

arcade::api::IGraphic *arcade::centipede::AEntity::getGraphic()
{
  return _graphic;
}

arcade::centipede::AEntity &
arcade::centipede::AEntity::operator=(arcade::centipede::AEntity const &c)
{
  if (this != &c)
  {
    this->_graphic = c._graphic;
    this->_pos = c._pos;
    this->_entityType = c._entityType;
    this->_size = c._size;
  }
  return *this;
}