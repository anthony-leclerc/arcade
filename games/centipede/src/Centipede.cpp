/*
** Centipede.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Centipede.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. avr. 08 12:51:42 2017 Anthony LECLERC
// Last update Thu Apr 13 08:49:03 2017 Sylvain Chaugny
*/

#include "Centipede.hpp"

arcade::centipede::Centipede &
arcade::centipede::Centipede::operator=(arcade::centipede::Centipede const &c)
{
  if (static_cast<AEntity const *>(this) != static_cast<AEntity const *>(&c))
  {
    _others = c._others;
    _parts = c._parts;
    _dir = DOWN;
    _lastDir = c._lastDir;
  }
  return (*this);
}

arcade::centipede::Centipede::Centipede(arcade::centipede::Grid const &grid,
                                        arcade::api::IGraphic *g) :
    AEntity(grid, g),
    _dir(DOWN),
    _lastDir(DOWN),
    _parts(),
    _others(),
    _spriteBodyID(-1)
{
  utl::Position pos(std::rand() % static_cast<int>(getMap().getWidth()), 0);
  setPosition(pos);
  for (int i = 0; i < 15 ; ++i)
  {
    CentipedeParts newpart(grid, getGraphic(), pos);
    newpart.setSprite(_spriteBodyID);
    _parts.push_back(newpart);
  }
}

arcade::centipede::Centipede::Centipede(arcade::centipede::Grid const &grid,
                                        arcade::api::IGraphic *g,
                                        std::list<arcade::centipede::CentipedeParts> const &body) :
    AEntity(grid, g),
    _dir(DOWN),
    _lastDir(DOWN),
    _parts(body),
    _others(),
    _spriteBodyID(-1)
{
  if (body.size() > 0)
    setPosition(body.begin()->getPosition());
}

void arcade::centipede::Centipede::reloadSprites(api::IGraphic *g)
{
  AEntity::resetGraphic(g);
  
  if (g)
  {
    _spriteBodyID = getGraphic()->loadSprite(TextureID::ENEMY, "ressource/player_body.png", utl::Position(),
					     utl::Dimensions(0, 0));
    for (auto &&p : _parts)
    {
      p.resetGraphic(g);
      p.setSprite(_spriteBodyID);
    }
    for (auto &&s : _others)
    {
      s.reloadSprites(g);
    }
  }
}

void arcade::centipede::Centipede::setOnMap(arcade::centipede::Grid &map) const
{
  for (auto &&p : _parts)
  {
    map.putEntity(&p);
  }
  std::for_each(_others.begin(), _others.end(),
                [&map](Centipede const& c) mutable {
                    c.setOnMap(map);
                });
}

bool arcade::centipede::Centipede::isHit(arcade::utl::Position const &pos) const
{
  if (std::find(_parts.begin(), _parts.end(), pos) == _parts.end())
  {
    for (Centipede const& c : _others)
    {
      if (c.isHit(pos))
      {
        return true;
      }
    }
    return false;
  }
  return true;
}

bool arcade::centipede::Centipede::onHit(arcade::utl::Position const &pos)
{
  std::list<CentipedeParts> splited;
  auto hit = std::find(_parts.begin(), _parts.end(), pos);
  if (hit != _parts.end())
  {
    splited.splice(splited.begin(), _parts, hit, _parts.end());
    splited.pop_front();
    if (splited.size() > 0)
      _others.emplace_back(this->getMap(), this->getGraphic(), splited);
    if (_parts.size() == 0)
    {
      if (_others.size() == 0)
        return true;
      _parts = _others.begin()->_parts;
      _others.splice(_others.end(), _others.begin()->_others);
      _dir = _others.begin()->_dir;
      _lastDir = _others.begin()->_lastDir;
      this->setPosition(_others.begin()->getPosition());
      _others.pop_front();
    }
    return false;
  }
  auto it = _others.begin();
  if (it != _others.end())
  {
    do
    {
      if (it->onHit(pos))
      {
        _others.erase(it);
        return false;
      }
      it++;
    } while (it != _others.end());
  }
  return false;
}

void arcade::centipede::Centipede::moveThis()
{
  utl::Position newPos;

  newPos = getPosition();
  switch (_dir)
  {
    case Direction::LEFT:
      newPos.x -= 1;
      break;
    case Direction::RIGHT:
      newPos.x += 1;
      break;
    case Direction::DOWN:
      newPos.y += 1;
    default:
      break;
  }
  if (getMap()(newPos.x, newPos.y) == TileType::OBSTACLE ||
      newPos.x < 0 ||
      newPos.x >= static_cast<int>(getMap().getWidth()))
  {
    if (_dir != Direction::DOWN)
    {
      _lastDir = _dir;
      _dir = Direction::DOWN;
      moveThis();
      return ;
    }
  }
  setPosition(newPos);
  _dir = _lastDir == Direction::LEFT ? Direction::RIGHT : Direction::LEFT;
}

void arcade::centipede::Centipede::move()
{
  utl::Position last;
  auto itget = _parts.rbegin();
  itget++;
  auto itlast = _parts.rbegin();
  while (itget != _parts.rend())
  {
    last = itget->getPosition();
    itlast->setPosition(last);
    itget++;
    itlast++;
  }
  moveThis();
  itlast->setPosition(this->getPosition());
  std::for_each(_others.begin(), _others.end(),
                [](Centipede& p) {
                    p.move();
                });
}

void arcade::centipede::Centipede::draw()
{
  for (auto &&c : _parts)
  {
    c.draw();
  }
  for (auto &&p : _others)
  {
    p.draw();
  }
}

void arcade::centipede::CentipedeParts::draw()
{
  if (graphic && _sprite_id != -1)
  {
    utl::Position dpos(this->getPosition());
    dpos.x += static_cast<int>(_map.getPosX());
    dpos.y += static_cast<int>(_map.getPosY());
    graphic->drawSprite(dpos, _sprite_id, utl::Color(255, 255, 255));
  }
}

void arcade::centipede::CentipedeParts::setSprite(int id)
{
  _sprite_id = id;
}

arcade::centipede::CentipedeParts &arcade::centipede::CentipedeParts::operator=(
    arcade::centipede::CentipedeParts const &s)
{
  if (this != &s)
  {
    _sprite_id = s._sprite_id;
    graphic = s.graphic;
    _pos = s._pos;
  }
  return *this;
}

void
arcade::centipede::CentipedeParts::setPosition(arcade::utl::Position const &pos)
{
  _pos = pos;
}

arcade::utl::Position arcade::centipede::CentipedeParts::getPosition() const
{
  return _pos;
}

bool arcade::centipede::CentipedeParts::operator==(
    arcade::utl::Position const &pos) const
{
  return _pos.x == pos.x && _pos.y == pos.y;
}

arcade::centipede::CentipedeParts::CentipedeParts(
    arcade::centipede::Grid const &map, arcade::api::IGraphic *g,
    arcade::utl::Position const &pos)  :
    _sprite_id(-1),
    graphic(g),
    _pos(pos),
    _map(map)
{}

void arcade::centipede::CentipedeParts::resetGraphic(arcade::api::IGraphic *g)
{
  graphic = g;
}
