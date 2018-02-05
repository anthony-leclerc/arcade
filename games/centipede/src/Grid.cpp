/*
** Grid.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Grid.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 17:22:39 2017 Anthony LECLERC
** Last update jeu. avr. 06 17:22:39 2017 Anthony LECLERC
*/

#include "Centipede.hpp"
#include "AEntity.hpp"

arcade::centipede::Grid::Grid(unsigned long width, unsigned long height) :
_width(width),
_height(height),
_posx(0),
_posy(0),
_map(width * height, TileType::EMPTY)
{}

arcade::centipede::Grid::Grid() : _width(0),
				  _height(0),
				  _posx(0),
				  _posy(0),
				  _map()
{}

void arcade::centipede::Grid::setDimensions(unsigned long width, unsigned long height)
{
  _width = width;
  _height = height;
  _map.resize(width * height, TileType::EMPTY);
}

void arcade::centipede::Grid::clear(void)
{
  std::fill(_map.begin(), _map.end(), TileType::EMPTY);
}

arcade::TileType arcade::centipede::Grid::operator()(int x, int y) const
{
  return _map[x + y * _width];
}

void
arcade::centipede::Grid::setPosition(unsigned long posx, unsigned long posy)
{
  _posx = posx;
  _posy = posy;
}

void arcade::centipede::Grid::putEntity(AEntity const * e)
{
  (*this)(e->getPosition().x, e->getPosition().y) = e->getType();
}

arcade::TileType &arcade::centipede::Grid::operator()(int x, int y)
{
  return _map[x + y * _width];
}

void
arcade::centipede::Grid::putEntity(arcade::centipede::CentipedeParts const *p)
{
  (*this)(p->getPosition().x, p->getPosition().y) = TileType::EVIL_DUDE;
}

std::vector<arcade::TileType> const &arcade::centipede::Grid::getMap() const
{
  return _map;
}
