//
// MainMenu.cpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/src/Core
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Apr  9 07:33:54 2017 Sylvain Chaugny
// Last update Sun Apr  9 10:00:11 2017 Sylvain Chaugny
//

#include	"MainMenu.hpp"
#include	"Engine.hpp"

arcade::MainMenu::MainMenu()
{
}

arcade::MainMenu::~MainMenu()
{
}

void		arcade::MainMenu::setGraphicModule(arcade::api::IGraphic *graphic)
{
  _graphic = graphic;
}

int		arcade::MainMenu::displayMainMenu(arcade::api::IEvents const &event)
{
  arcade::utl::Position infos_pos;
  arcade::utl::Color color(255, 255, 255);
  arcade::utl::Dimensions infos_dim;
  std::string	msg;
  int		i;

  infos_dim.width = _graphic->getDimensions().width / 2;
  infos_dim.height = _graphic->getDimensions().height / 2;
  infos_pos.x = _graphic->getDimensions().width / 2 - infos_dim.width / 2;
  infos_pos.y = _graphic->getDimensions().height / 2 - infos_dim.height / 2;

  _graphic->drawRectangle(infos_pos, infos_dim.width, infos_dim.height, false, arcade::utl::Color(255, 0, 0));
  msg = "Welcome to Arcade !!";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 1), msg, arcade::utl::Color(0, 255, 0));

  msg = "Use UP and DOWN to switch between";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 4), msg, arcade::utl::Color(255, 255, 255));

  i = 5;
  for (t_tab_i iter = _libs_tab.begin(); iter != _libs_tab.end(); iter++)
    {
      color._color.g = (*iter == _current_graphic) ? 0 : 255;
      msg = (*iter == _current_graphic) ? "< " + *iter + " >" : *iter;
      _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + i), msg, color);
      i++;
    }

  msg = "And use z and s to select";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + i), msg, arcade::utl::Color(255, 255, 255));
  i += 2;
  for (t_tab_i iter = _games_tab.begin(); iter != _games_tab.end(); iter++)
    {
      color._color.r = (*iter == _current_game) ? 0 : 255;
      msg = (*iter == _current_game) ? "< " + *iter + " >" : *iter;
      _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + i), msg, color);
      i++;
    }
  i += 2;
  msg = "Press SPACE to start !";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + i), msg, arcade::utl::Color(255, 255, 255));

  if (event.keyPressed(arcade::api::IEvents::Key::UP))
    return 1;
  if (event.keyPressed(arcade::api::IEvents::Key::DOWN))
    return 2;
  if (event.keyPressed(arcade::api::IEvents::Key::Z))
    return 3;
  if (event.keyPressed(arcade::api::IEvents::Key::S))
    return 4;
  if (event.keyPressed(arcade::api::IEvents::Key::SPACE))
    return 5;
  return (0);
}

std::string	arcade::MainMenu::parseName(std::string const &name)
{
  std::string	new_name;

  new_name = name.substr(name.find("lib_arcade_") + 11, name.length());
  new_name = new_name.substr(0, new_name.length() - 3);
  return new_name;
}

void		arcade::MainMenu::addLibName(std::string const &name)
{
  _libs_tab.push_back(parseName(name));
}

void		arcade::MainMenu::addGameName(std::string const &name)
{
  _games_tab.push_back(parseName(name));
}

void		arcade::MainMenu::setCurrentGame(std::string const &name)
{
  _current_game = parseName(name);
}

void		arcade::MainMenu::setCurrentGraphic(std::string const &name)
{
  _current_graphic = parseName(name);
}
