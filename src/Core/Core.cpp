/*
** Core.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Core.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. avr. 03 22:11:52 2017 Anthony LECLERC
// Last update Sun Apr  9 11:05:50 2017 Sylvain Chaugny
*/

#include "Core.hpp"

arcade::Core::Core(int ac, char **av) :
  _error(NONE),
  _graphicLoader(),
  _gameLoader(),
  _currentGraphic(),
  _currentGame(),
  _engine(),
  _framerate(25),
  _coreActions()
{
  if (ac < 2)
    {
      std::cerr << "Usage: " << av[0] << " [graphic_library_path]" << std::endl;
      _error = INVARG;
    }
  else if (_graphicLoader.loadLibrary(av[1]) == 1)
    {
      std::cerr << "Error: " << "graphic library " << av[1] << " failed to load" << std::endl;
      _error = NOGRAPHIC;
    }
  _coreActions[Engine::MENU] = &Core::menu;
  _coreActions[Engine::PREV_GAME] = &Core::prevGame;
  _coreActions[Engine::NEXT_GAME] = &Core::nextGame;
  _coreActions[Engine::NEXT_GRAPHIC] = &Core::nextGraphic;
  _coreActions[Engine::PREV_GRAPHIC] = &Core::prevGraphic;
  _coreActions[Engine::RESTART] = &Core::restartEngine;
}

int arcade::Core::play()
{
  Engine::Action status;

  if (_error)
    return (1);
  do
  {
    status = playGameFrame();
    if (status != Engine::EXIT)
      _framerate.waitFrame();
  } while (status != Engine::EXIT);
  _engine.stop();
  return 0;
}

bool arcade::Core::setup(std::string const &gamepath, std::string const &graphicpath)
{
  if (_error)
    return (false);
  if (_graphicLoader.loadLibraries(graphicpath.c_str()) == 1)
    {
      std::cerr << "Failed to load graphics library." << std::endl;
      return false;
    }
  if (_gameLoader.loadLibraries(gamepath.c_str()) == 1)
    {
      std::cerr << "Failed to load games library" << std::endl;
      return false;
    }
  _currentGame = _gameLoader.begin();
  _currentGraphic = _graphicLoader.begin();
  try
    {
      _engine.setGraphicContext(_currentGraphic->getInstance());
      _engine.setGameContext(_currentGame->getInstance());
      _engine.getMainMenu().setCurrentGraphic(_currentGraphic->getFileName());
      _engine.getMainMenu().setCurrentGame(_currentGame->getFileName());
    }
  catch (::utl::loaderException const& e)
    {
      std::cerr << "CoreSetup: " << e.what() << std::endl;
      return (false);
    }
  _engine.getMainMenu().setGraphicModule(_engine.getGraphicModule());

  for (::utl::DLLoaderManager <arcade::api::IContext> ::iterator i = _graphicLoader.begin();
       i != _graphicLoader.end();
       i++)
    _engine.getMainMenu().addLibName(i->getFileName());
  for (::utl::DLLoaderManager <arcade::api::AGame> ::iterator i = _gameLoader.begin();
       i != _gameLoader.end();
       i++)
    _engine.getMainMenu().addGameName(i->getFileName());
  return (true);
}

arcade::Engine::Action arcade::Core::playGameFrame()
{
  Engine::Action status;

  status = _engine.run();
  if (!_framerate.allowAction())
    return status;
  switch (status)
  {
    case Engine::PREV_GAME:
      _currentGame = (_currentGame == _gameLoader.begin()) ? _gameLoader.end() - 1 : _currentGame - 1;
      _engine.getMainMenu().setCurrentGame(_currentGame->getFileName());
      _engine.setGameContext(_currentGame->getInstance());
      _framerate.actionAllowed();
      break;
    case Engine::NEXT_GAME:
      _currentGame = (_currentGame == _gameLoader.end() - 1) ? _gameLoader.begin(): _currentGame + 1;
      _engine.getMainMenu().setCurrentGame(_currentGame->getFileName());
      _engine.setGameContext(_currentGame->getInstance());
      _framerate.actionAllowed();
      break;
    case Engine::PREV_GRAPHIC:
      _currentGraphic = (_currentGraphic == _graphicLoader.begin()) ? _graphicLoader.end() - 1 : _currentGraphic - 1;
      _engine.getMainMenu().setCurrentGraphic(_currentGraphic->getFileName());
      _engine.setGraphicContext(_currentGraphic->getInstance());
      _framerate.actionAllowed();
      break;
    case Engine::NEXT_GRAPHIC:
      _currentGraphic = (_currentGraphic == _graphicLoader.end() - 1) ? _graphicLoader.begin(): _currentGraphic + 1;
      _engine.getMainMenu().setCurrentGraphic(_currentGraphic->getFileName());
      _engine.setGraphicContext(_currentGraphic->getInstance());
      _framerate.actionAllowed();
      break;
    case Engine::RESTART:
      _engine.getGame().restart();
      _framerate.actionAllowed();
      break;
    case Engine::MENU:
      _engine.setInMenu(true);
      // Go to Core menu
      _framerate.actionAllowed();
      break;
  case Engine::EXIT:
    return Engine::EXIT;
  default: return Engine::RUN;
  }
  return (status);
}

int arcade::Core::nextGraphic(void)
{
  if (_graphicLoader.size() == 0)
    return 1;
  if (_currentGraphic == _graphicLoader.end() - 1)
    _currentGraphic = _graphicLoader.begin();
  else
    _currentGraphic = _currentGraphic + 1;
  _engine.setGraphicContext(_currentGraphic->getInstance());
  return 0;
}

int arcade::Core::prevGraphic(void)
{
  if (_graphicLoader.size() == 0)
    return 1;
  if (_currentGraphic == _graphicLoader.begin())
    _currentGraphic = _graphicLoader.end() - 1;
  else
    _currentGraphic = _currentGraphic - 1;
  _engine.setGraphicContext(_currentGraphic->getInstance());
  return 0;
}

int arcade::Core::nextGame(void)
{
  if (_gameLoader.size() == 0)
    return 1;
  if (_currentGame == _gameLoader.end() - 1)
    _currentGame = _gameLoader.begin();
  else
    _currentGame = _currentGame + 1;
  _engine.setGameContext(_currentGame->getInstance());
  return 0;
}

int arcade::Core::prevGame(void)
{
  if (_gameLoader.size() == 0)
    return 1;
  if (_currentGame == _gameLoader.begin())
    _currentGame = _gameLoader.end() - 1;
  else
    _currentGame = _currentGame - 1;
  _engine.setGameContext(_currentGame->getInstance());
  return 0;
}

int arcade::Core::restartEngine(void)
{
  return _engine.restart();
}

int arcade::Core::menu()
{
  return 0;
}

char const *arcade::Core::getstrError() const
{
  switch (_error)
  {
    case INVARG: return "Invalid argument in command line";
    case NOGAME: return "Game loader error";
    case NOGRAPHIC: return "Graphic loader error";
    case INTERNAL: return "Internal error occured";
    default: return "No error occured";
  }
}
