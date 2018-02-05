//
// SnakeMenu.cpp for arcade in /home/sylvain/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Apr  7 19:33:09 2017 Sylvain Chaugny
// Last update Sun Apr  9 11:00:35 2017 Sylvain Chaugny
//

#include	"utils/Color.hpp"
#include	"utils/Position.hpp"
#include	"SnakeMenu.hpp"

int		arcade::snake::SnakeMenu::displaySetup(arcade::api::IEvents const &event,
						       arcade::utl::Dimensions &board)
{
  std::string	msg;
  arcade::utl::Position infos_pos;
  arcade::utl::Dimensions infos_dim;

  infos_dim.width = _graphic->getDimensions().width / 2;
  infos_dim.height = _graphic->getDimensions().height / 2;
  infos_pos.x = _graphic->getDimensions().width / 2 - infos_dim.width / 2;
  infos_pos.y = _graphic->getDimensions().height / 2 - infos_dim.height / 2;

  _graphic->drawRectangle(infos_pos, infos_dim.width, infos_dim.height, false, arcade::utl::Color(255, 0, 0));

  msg = "Setup";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 1), msg, arcade::utl::Color(255, 0, 0));

  msg = "WIDTH (use LEFT and RIGHT)";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 3), msg, arcade::utl::Color(0, 255, 255));

  msg = "<-  " + std::to_string(board.width) + "  ->";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 4), msg, arcade::utl::Color(0, 255, 0));

  msg = "HEIGHT (use UP and DOWN)";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 5), msg, arcade::utl::Color(0, 255, 255));

  msg = "<-  " + std::to_string(board.height) + "  ->";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 6), msg, arcade::utl::Color(0, 255, 0));

  msg = "Press SPACE to continue";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + infos_dim.height - 2), msg, arcade::utl::Color(0, 255, 255));

  if (board.width > 10)
    {
      if (event.keyPressed(arcade::api::IEvents::Key::LEFT))
	board.width--;
      if (event.keyPressed(arcade::api::IEvents::Key::RIGHT))
	board.width++;
    }
  if (board.height > 10)
    {
      if (event.keyPressed(arcade::api::IEvents::Key::UP))
	board.height++;
      if (event.keyPressed(arcade::api::IEvents::Key::DOWN))
	board.height--;
    }
  if (event.keyPressed(arcade::api::IEvents::Key::SPACE))
    {
      _setup = false;
      return 1;
    }
  return 0;
}

int		arcade::snake::SnakeMenu::displayMenu(arcade::api::IEvents const &event)
{
  arcade::utl::Position infos_pos;
  arcade::utl::Dimensions infos_dim;
  std::string	msg;

  infos_dim.width = _graphic->getDimensions().width / 2;
  infos_dim.height = _graphic->getDimensions().height / 2;
  infos_pos.x = _graphic->getDimensions().width / 2 - infos_dim.width / 2;
  infos_pos.y = _graphic->getDimensions().height / 2 - infos_dim.height / 2;

  _graphic->drawRectangle(infos_pos, infos_dim.width, infos_dim.height, false, arcade::utl::Color(255, 0, 0));

  msg = "Welcome to Snake";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 1), msg, arcade::utl::Color(255, 0, 0));

  msg = "Press s to enter setup";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 4), msg, arcade::utl::Color(255, 255, 255));

  msg = "Press r to start";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 5), msg, arcade::utl::Color(255, 255, 255));

  msg = "Press e to start (easy mode)";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 6), msg, arcade::utl::Color(255, 255, 255));


  if (event.keyPressed(arcade::api::IEvents::Key::R))
    return (1);
  if (event.keyPressed(arcade::api::IEvents::Key::E))
    return (2);
  if (event.keyPressed(arcade::api::IEvents::Key::S))
    {
      _setup = true;
      return 1;
    }
  return (0);
}

int		arcade::snake::SnakeMenu::displayGameOver(arcade::api::IEvents const &event,
							  int score)
{
  arcade::utl::Position infos_pos;
  arcade::utl::Dimensions infos_dim;
  std::string	str_score;
  std::string	msg;

  str_score = "Score: " + std::to_string(score);
  infos_dim.width = _graphic->getDimensions().width / 2;
  infos_dim.height = _graphic->getDimensions().height / 2;
  infos_pos.x = _graphic->getDimensions().width / 2 - infos_dim.width / 2;
  infos_pos.y = _graphic->getDimensions().height / 2 - infos_dim.height / 2;

  _graphic->drawRectangle(infos_pos, infos_dim.width, infos_dim.height, false, arcade::utl::Color(255, 0, 0));

  msg = "Game Over";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg), infos_pos.y + 1), msg, arcade::utl::Color(255, 0, 0));

  msg = "Snake";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + 3), msg, arcade::utl::Color(0, 255, 0));

  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(str_score) / 2, infos_pos.y + 4), str_score, arcade::utl::Color(0, 255, 255));

  msg = "Press s to enter setup";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + infos_dim.height - 4), msg, arcade::utl::Color(255, 255, 255));

  msg = "Press r to restart";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + infos_dim.height - 3), msg, arcade::utl::Color(255, 255, 255));

  msg = "Press e to restart (easy mode)";
  _graphic->drawText(arcade::utl::Position(_graphic->getDimensions().width / 2 - _graphic->getStrlen(msg) / 2, infos_pos.y + infos_dim.height - 2), msg, arcade::utl::Color(255, 255, 255));

  if (event.keyPressed(arcade::api::IEvents::Key::R))
    return (1);
  if (event.keyPressed(arcade::api::IEvents::Key::E))
    return (2);
  if (event.keyPressed(arcade::api::IEvents::Key::S))
    {
      _setup = true;
      return 1;
    }
  return 0;
}
