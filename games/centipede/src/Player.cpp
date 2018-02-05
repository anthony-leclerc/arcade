/*
** Player.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Player.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 18:23:16 2017 Anthony LECLERC
// Last update Thu Apr 13 08:54:19 2017 Sylvain Chaugny
*/

#include	"Player.hpp"

void arcade::centipede::Player::move()
{
  utl::Position pos = this->getPosition();
  switch (_dir)
  {
    case Direction::UP:
      if (static_cast<unsigned long>(pos.y) > getMap().getHeight() - 7)
	this->setPosition(utl::Position(pos.x, pos.y - 1));
      break;
    case Direction::DOWN:
      if (static_cast<unsigned long>(pos.y) < getMap().getHeight() - 1)
	this->setPosition(utl::Position(pos.x, pos.y + 1));
      break;
    case Direction::LEFT:
      if (pos.x > 0)
	this->setPosition(utl::Position(pos.x - 1, pos.y));
      break;
    case Direction::RIGHT:
      if (static_cast<unsigned long>(pos.x) < getMap().getWidth() - 1)
	this->setPosition(utl::Position(pos.x + 1, pos.y));
      break;
    default: break;
  }
  _shot.move();
}

void arcade::centipede::Player::draw()
{
  utl::Position dpos(this->getPosition());
  dpos.x += static_cast<int>(this->getMap().getPosX());
  dpos.y += static_cast<int>(this->getMap().getPosY());
  getGraphic()->drawSprite(dpos, _spriteID, utl::Color(255, 0, 0));
  _shot.draw();
}

bool arcade::centipede::Player::shotHit(arcade::centipede::AEntity &e)
{
  return _shot.hit(e);
}

arcade::utl::Position const &arcade::centipede::Player::getShotPosition() const
{
  return _shot.getPosition();
}

void arcade::centipede::Player::shot()
{
  if (_shot.getPosition().y == -1)
    _shot.setPosition(utl::Position(this->getPosition().x, this->getPosition().y - 1));
}

void arcade::centipede::Player::setDirection(arcade::centipede::Direction dir)
{
  _dir = dir;
}

void arcade::centipede::Player::setSprite(int id)
{
  _spriteID = id;
}

arcade::centipede::Player::Player(arcade::centipede::Grid const &map,
				  arcade::api::IGraphic *graphic) :
    AEntity(map, graphic),
    _dir(Direction::NONE),
    _shot(map, graphic),
    _spriteID(-1)
{

}

void arcade::centipede::Player::resetGraphic(arcade::api::IGraphic *g)
{
  AEntity::resetGraphic(g);
  int id = g->loadSprite(TextureID::PLAYER_HEAD, "ressource/player_head.png",
                         utl::Position(0, 0),
                         utl::Dimensions(0, 0));
  setSprite(id);
  _shot.resetGraphic(g);
}

void arcade::centipede::Player::playerShot::move()
{
  this->setPosition(utl::Position(this->getPosition().x, this->getPosition().y - 1));
  if (this->getPosition().y < 0)
    this->setPosition(utl::Position(-1, -1));
}

bool arcade::centipede::Player::playerShot::hit(arcade::centipede::AEntity &e)
{
  bool ret;
  ret = e.onHit(this->getPosition());
  this->setPosition(utl::Position(-1 ,-1));
  return ret;
}

void arcade::centipede::Player::playerShot::draw()
{
  if (getPosition().x != -1 && _sprite_id != -1)
  {
    utl::Position drawPos = this->getPosition();
    drawPos.x += static_cast<int>(this->getMap().getPosX());
    drawPos.y += static_cast<int>(this->getMap().getPosY());
    getGraphic()->drawSprite(drawPos, _sprite_id,
			utl::Color(0, 255, 0));
  }
}

arcade::centipede::Player::playerShot::playerShot(
    arcade::centipede::Grid const &map, arcade::api::IGraphic *graphic) :
    AEntity(map, graphic, utl::Position(-1, -1)), _sprite_id(-1)
{
      if (graphic)
	_sprite_id = graphic->loadSprite(TextureID::SHOT, "ressource/shot.png",
					 utl::Position(),
					 utl::Dimensions());
}

void
arcade::centipede::Player::playerShot::resetGraphic(arcade::api::IGraphic *g)
{
  AEntity::resetGraphic(g);
  if (g)
    _sprite_id = g->loadSprite(TextureID::SHOT, "ressource/shot.png",
                               utl::Position(),
                             utl::Dimensions());
}

