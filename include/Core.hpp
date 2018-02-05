/*
** Core.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Core.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. avr. 03 22:11:52 2017 Anthony LECLERC
// Last update Sun Apr  9 07:55:15 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_CORE_HPP
# define CPP_ARCADE_CORE_HPP

# include  <map>
#include "Framerate.hpp"
#include "loader/DLLoaderManager.hpp"
#include "API/IContext.hpp"
#include "API/AGame.hpp"
#include "Engine.hpp"

namespace arcade {
  class Core {
  private:

    enum Error {
      NONE,
      INVARG,
      NOGAME,
      NOGRAPHIC,
      INTERNAL
    } _error;

    ::utl::DLLoaderManager <arcade::api::IContext> _graphicLoader;
    ::utl::DLLoaderManager <arcade::api::AGame> _gameLoader;

    ::utl::DLLoaderManager <arcade::api::IContext>::iterator _currentGraphic;
    ::utl::DLLoaderManager <arcade::api::AGame>::iterator _currentGame;

    Engine _engine;
    Framerate _framerate;

    std::map <Engine::Action, int (Core::*)(void)> _coreActions;

    int nextGraphic(void);
    int prevGraphic(void);
    int nextGame(void);
    int prevGame(void);
    int restartEngine(void);
    int menu();

  public:
    // Parser argument
    Core(int ac, char **av);
    ~Core() {};

    // Load libs
    bool setup(std::string const& gamepath, std::string const& graphicpath);

    // Launch loop
    int play();
    Engine::Action playGameFrame();
    char const *getstrError() const;
  };
}

#endif /* !CPP_ARCADE_CORE_HPP */
