/*
** Engine.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Engine.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. avr. 03 22:24:11 2017 Anthony LECLERC
// Last update Sun Apr  9 11:05:39 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_ENGINE_HPP
# define CPP_ARCADE_ENGINE_HPP

# include  <map>
#include "API/IContext.hpp"
#include "API/AGame.hpp"
#include "API/IEvents.hpp"
#include "MainMenu.hpp"

namespace arcade {
  class Engine {
  public:
    enum Action {
      RUN,
      NEXT_GRAPHIC,
      PREV_GRAPHIC,
      NEXT_GAME,
      PREV_GAME,
      RESTART,
      MENU,
      EXIT
    };
  private:
    api::IContext *_context;
    api::AGame *_game;
    api::IEvents *_events;
    std::map<Action, api::IEvents::Key> _keyActions;
    MainMenu _main_menu;
    bool _in_menu;

  public:
    Engine();
    ~Engine();

    void setGraphicContext(api::IContext *context);
    void setGameContext(api::AGame *game);

    api::IGraphic *getGraphicModule() { return &(_context->getGraphic()); }
    MainMenu &getMainMenu() { return _main_menu; }
    api::AGame &getGame() { return *_game; }
    api::IContext &getContext() { return *_context; }
    void setInMenu(bool in_menu) { _in_menu = in_menu; }

    Engine::Action run();
    int stop();
    int restart();
  };
}


#endif /* !CPP_ARCADE_ENGINE_HPP */
