/*
** Obstacle.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Obstacle.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. avr. 07 14:38:45 2017 Anthony LECLERC
// Last update Sun Apr  9 11:22:08 2017 Anthony LECLERC
*/

#include <iostream>
#include "Obstacle.hpp"

arcade::utl::Color const arcade::centipede::Obstacle::States[5] = {
    utl::Color(255, 0, 0),
    utl::Color(255, 255, 0),
    utl::Color(255, 255, 0),
    utl::Color(255, 255, 0),
    utl::Color(0, 255, 0)
};

void arcade::centipede::Obstacle::move()
{}

bool arcade::centipede::Obstacle::onHit(arcade::utl::Position const &)
{
  _pv--;
  return (_pv == 0);
}

void arcade::centipede::Obstacle::draw()
{
  utl::Position dpos(this->getPosition());
  dpos.x += static_cast<int>(this->getMap().getPosX());
  dpos.y += static_cast<int>(this->getMap().getPosY());
  getGraphic()->drawSprite(dpos, sprite_id, States[_pv - 1]);
}

arcade::centipede::Obstacle::Obstacle(arcade::centipede::Grid const &map,
                                      arcade::api::IGraphic *Graphic,
                                      arcade::utl::Position pos,
                                      arcade::utl::Dimensions dim) :
  AEntity(map, Graphic, pos, dim), _pv(5), sprite_id(-1) {
  if (Graphic)
    sprite_id = Graphic->loadSprite(TextureID::WALL, "ressource/wall.png", utl::Position(), utl::Dimensions());
  setType(TileType::OBSTACLE);
}

void arcade::centipede::Obstacle::resetGraphic(arcade::api::IGraphic *g)
{
  AEntity::resetGraphic(g);
  sprite_id = g->loadSprite(TextureID::WALL, "ressource/wall.png",
                            utl::Position(), utl::Dimensions());
}
