/*
** Engine.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Engine.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. avr. 03 22:24:11 2017 Anthony LECLERC
// Last update Sun Apr  9 09:41:03 2017 Sylvain Chaugny
*/

#include <algorithm>
#include "exceptions/loaderExceptions.hpp"
#include "Engine.hpp"
#include "API/Exceptions.hpp"

arcade::Engine::Engine() : _context(0), _game(0), _events(0), _keyActions()
{
  _keyActions[PREV_GRAPHIC] = api::IEvents::Key::KEY_2;
  _keyActions[NEXT_GRAPHIC] = api::IEvents::Key::KEY_3;
  _keyActions[PREV_GAME] = api::IEvents::Key::KEY_4;
  _keyActions[NEXT_GAME] = api::IEvents::Key::KEY_5;
  _keyActions[RESTART] = api::IEvents::Key::KEY_8;
  _keyActions[MENU] = api::IEvents::Key::KEY_9;
  _keyActions[EXIT] = api::IEvents::Key::ESCAPE;
  _in_menu = true;
}

arcade::Engine::~Engine()
{}

void arcade::Engine::setGraphicContext(arcade::api::IContext *context)
{
  if (_context)
    {
      _context->stop();
    }
  _context = context;
  if (!_context)
    throw ::utl::loaderException("Context interface error");
  _context->init();
  if (_game)
    {
      _game->setGraphicModule(&_context->getGraphic());
      _game->reloadSprites();
    }
  _main_menu.setGraphicModule(&_context->getGraphic());
  _events = &context->getEvents();
  if (_events == NULL)
    throw ::utl::loaderException("Event interface error");
}

void arcade::Engine::setGameContext(arcade::api::AGame *game)
{
  if (_game)
    {
      _game->close();
    }
  _game = game;
  if (_context)
    {
      try
	{
	  _game->init(&_context->getGraphic());
	}
      catch (arcade::api::GameException const &e)
	{
	  std::cerr << "Error: Game: " << e.what() << std::endl;
	  throw ::utl::loaderException("Game initialization error");
	  return ;
	}
    }
}

arcade::Engine::Action arcade::Engine::run()
{
  int ret;

  if (!_context || !_game || !_events)
    {
      return EXIT;
    }
  _events->pollEvents();
  auto it = std::find_if(_keyActions.begin(), _keyActions.end(),
  [this](auto &&i) {
      return (_events->keyPressed(i.second));
  });
  if (it != _keyActions.end())
    return it->first;

  if (_events->keyPressed(_keyActions[EXIT]))
    return EXIT;
  _context->clear();

  try
    {
      if (_in_menu)
	{
	  ret = _main_menu.displayMainMenu(*_events);
	  _context->display();
	  switch (ret)
	    {
	    case (1) : return PREV_GRAPHIC;
	    case (2) : return NEXT_GRAPHIC;
	    case (3) : return PREV_GAME;
	    case (4) : return NEXT_GAME;
	    case (5) : _in_menu = false;
	    default : return RUN;
	    }
	}
      else
	_game->play(*_events);
    }
  catch (arcade::api::GameException const &e)
    {
      std::cerr << "Error: Game: " << e.what() << std::endl;
      return EXIT;
    }
  _context->display();
  return RUN;
}

int arcade::Engine::restart()
{
  if (!_game)
    _game->restart();
  return 0;
}

int arcade::Engine::stop()
{
  _game->close();
  _context->stop();
  return (0);
}
