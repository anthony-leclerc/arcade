//
// SnakeCell.cpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Mar 19 23:10:19 2017 Sylvain Chaugny
// Last update Tue Apr  4 10:16:38 2017 Sylvain Chaugny
//

#include	"SnakeCell.hpp"
#include	"API/IEvents.hpp"

arcade::snake::SnakeCell::SnakeCell()
{
  _is_head = 0;
  _is_new = false;
  _pos.x = 0;
  _pos.y = 0;
  _direction = arcade::api::IEvents::Key::RIGHT;
}

arcade::snake::SnakeCell::~SnakeCell()
{
}

void		arcade::snake::SnakeCell::setIsHead(bool	is_head)
{
  _is_head = is_head;
}

bool		arcade::snake::SnakeCell::getIsHead() const
{
  return _is_head;
}

void		arcade::snake::SnakeCell::setIsNew(bool	is_new)
{
  _is_new = is_new;
}

bool		arcade::snake::SnakeCell::getIsNew() const
{
  return _is_new;
}

arcade::api::IEvents::Key	arcade::snake::SnakeCell::getDirection() const
{
  return _direction;
}

void		arcade::snake::SnakeCell::setDirection(arcade::api::IEvents::Key event)
{
  _direction = event;
}

void		arcade::snake::SnakeCell::updatePosition()
{
  if (_direction == arcade::api::IEvents::Key::UP)
    _pos.y = _pos.y - 1;
  else if (_direction == arcade::api::IEvents::Key::DOWN)
    _pos.y = _pos.y + 1;
  else if (_direction == arcade::api::IEvents::Key::LEFT)
    _pos.x = _pos.x - 1;
  else if (_direction == arcade::api::IEvents::Key::RIGHT)
    _pos.x = _pos.x + 1;
}
