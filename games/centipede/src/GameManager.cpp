/*
** GameManager.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/GameManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. avr. 09 05:48:53 2017 Anthony LECLERC
// Last update Sun Apr  9 11:23:41 2017 Anthony LECLERC
*/

#include "GameManager.hpp"

unsigned long const arcade::centipede::GameManager::BoardWidth = 50;
unsigned long const arcade::centipede::GameManager::BoardHeight = 30;

void arcade::centipede::GameManager::setMap(unsigned long width, unsigned long height)
{
  _map.setDimensions(width, height);
  _obstacles.resize(20);
  for (int i = 0; i < 20; ++i)
  {
    utl::Position pos(std::rand() % static_cast<int>(_map.getWidth()), +
	(std::rand() % static_cast<int>(_map.getHeight() / 2)));
    _obstacles[i] = new Obstacle(_map, graphic, pos);
  }
}


void arcade::centipede::GameManager::gameDataInit(unsigned long width,
                                                  unsigned long height)
{
  setMap(width, height);
  _player = new Player(_map, graphic);
  _player->setPosition(utl::Position(static_cast<int>(width / 2),
                                     static_cast<int>(height - 2)));
  _ennemy = new Centipede(_map, graphic);
  refreshMap();
}

arcade::centipede::Direction
arcade::centipede::GameManager::getDirection(arcade::api::IEvents const &e)
{
  if (e.keyPressed(api::IEvents::LEFT))
    return Direction::LEFT;
  if (e.keyPressed(api::IEvents::RIGHT))
    return Direction::RIGHT;
  if (e.keyPressed(api::IEvents::UP))
    return Direction::UP;
  if (e.keyPressed(api::IEvents::DOWN))
    return Direction::DOWN;
  return Direction::NONE;
}

int arcade::centipede::GameManager::init(arcade::api::IGraphic *gr)
{
  setGraphicModule(gr);
  gameDataInit(BoardWidth,
	       BoardHeight);
  _map.setPosition(graphic->getDimensions().width / 4, 0);
  reloadSprites();
  return (0);
}

void arcade::centipede::GameManager::refreshMap()
{
  _map.clear();
  _map.putEntity(_player);
  _ennemy->setOnMap(_map);
  for (auto &&p : _obstacles)
  {
    _map.putEntity(p);
  }
}

int arcade::centipede::GameManager::play(arcade::api::IEvents const &event)
{
  getInputs(event);
  if (update() == 1)
    return 1;
  display();
  return 0;
}

int arcade::centipede::GameManager::reloadSprites()
{
  unsigned long x;
  unsigned long y;

  x = (graphic->getDimensions().width - _map.getWidth()) / 2;
  y = (graphic->getDimensions().height - _map.getHeight()) / 2;
  x = (x > graphic->getDimensions().width) ? 0 : x;
  y = (y > graphic->getDimensions().height) ? 0 : y;
  _map.setPosition(x, y);
  _player->resetGraphic(graphic);
  _ennemy->reloadSprites(graphic);
  for (auto &&p : _obstacles)
  {
    p->resetGraphic(graphic);
  }
  return 0;
}

int arcade::centipede::GameManager::close()
{
  delete _player;
  delete _ennemy;
  for (auto &&p : _obstacles) { delete p; p = 0; }
  _player = 0;
  _ennemy = 0;
  return 0;
}

void arcade::centipede::GameManager::display()
{
  graphic->drawRectangle(utl::Position(static_cast<int>(_map.getPosX() - 1),
                                       static_cast<int>(_map.getPosY()) - 1),
                         _map.getWidth() + 2,
                         _map.getHeight() + 1,
                         false,
                         utl::Color(0, 0, 255));
  for (auto&& o : _obstacles) { o->draw(); }
  _player->draw();
  _ennemy->draw();
}

void
arcade::centipede::GameManager::getInputs(arcade::api::IEvents const &event)
{
  if (event.keyPressed(api::IEvents::SPACE))
    _player->shot();
  _player->setDirection(getDirection(event));
}

int arcade::centipede::GameManager::update()
{
  _player->move();
  _ennemy->move();
  if (_ennemy->getPosition().y >= static_cast<int>(_map.getHeight() - 1))
    return 1;
  refreshMap();
  if (_player->getShotPosition().x == -1 || _player->getShotPosition().y == -1)
    return (0);
  if (_map(_player->getShotPosition().x, _player->getShotPosition().y) != TileType::EMPTY)
  {
    if (_ennemy->isHit(_player->getShotPosition()))
    {
      _obstacles.push_back(new Obstacle(_map, graphic, _player->getShotPosition()));
      if (_player->shotHit(*_ennemy))
      {
        return (1);
      }
    }
    else
    {
      std::vector<AEntity *>::iterator obstacle;
      obstacle = (std::find_if(_obstacles.begin(), _obstacles.end(),
                               [this](AEntity *e) {
                                   return *e == _player->getShotPosition();
                               }));
      if (obstacle != _obstacles.end())
      {
        if (_player->shotHit(*(*obstacle)))
          _obstacles.erase(obstacle);
      }
    }
  }
  return (0);
}

int arcade::centipede::GameManager::restart()
{
  _score = 0;
  close();
  init(graphic);
  return 0;
}

int arcade::centipede::GameManager::getScore() const
{
  return 0;
}

arcade::centipede::GameManager::~GameManager()
{
  delete _player;
  delete _ennemy;
  for (auto &&p : _obstacles)
  {
    delete p;
  }
}

arcade::centipede::GameManager::GameManager():
    _player(0),
    _ennemy(0),
    _obstacles(),
    _map(),
    _score(0)
{}
