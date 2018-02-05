//
// EventsNcurse.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse/src
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Thu Mar 23 14:26:00 2017 Sylvain Chaugny
// Last update Sun Apr  9 09:52:54 2017 Sylvain Chaugny
//

#include	<algorithm>
#include	<curses.h>
#include <iostream>
#include	"EventsNcurse.hpp"

arcade::libncurse::EventsNcurse::EventsNcurse()
{
}

arcade::libncurse::EventsNcurse::~EventsNcurse()
{
}

void		arcade::libncurse::EventsNcurse::pollEvents()
{
  timeout(1);
  _keys.clear();
  for (int i = 0; i < 12; i++)
    {
      keypad(stdscr, TRUE);
      _keys.push_back(getCorrespondingKey(getch()));
    }
}

arcade::api::IEvents::Key	arcade::libncurse::EventsNcurse::getCorrespondingKey(int c) const
{
  arcade::api::IEvents::Key	key;

  switch (c)
    {
      /*
      ** MOVING KEYS
      */

    case (KEY_LEFT):
      key = arcade::api::IEvents::Key::LEFT;
      break;
    case (KEY_RIGHT):
      key = arcade::api::IEvents::Key::RIGHT;
      break;
    case (KEY_DOWN):
      key = arcade::api::IEvents::Key::DOWN;
      break;
    case (KEY_UP):
      key = arcade::api::IEvents::Key::UP;
      break;
    case ('z'):
      key = arcade::api::IEvents::Key::Z;
      break;
    case ('q'):
      key = arcade::api::IEvents::Key::Q;
      break;
    case ('s'):
      key = arcade::api::IEvents::Key::S;
      break;
    case ('d'):
      key = arcade::api::IEvents::Key::D;
      break;

      /*
      ** GAME KEYS
      */

    case ('r'):
      key = arcade::api::IEvents::Key::R;
      break;
    case ('e'):
      key = arcade::api::IEvents::Key::E;
      break;
    case ('l'):
      key = arcade::api::IEvents::Key::L;
      break;
    case ('g'):
      key = arcade::api::IEvents::Key::G;
      break;
    case (' '):
      key = arcade::api::IEvents::Key::SPACE;
      break;

      /*
      ** INTERACTING KEYS
      */

    case (27):
      key = arcade::api::IEvents::Key::ESCAPE;
      break;
    case ('2'):
      key = arcade::api::IEvents::Key::KEY_2;
      break;
    case ('3'):
      key = arcade::api::IEvents::Key::KEY_3;
      break;
    case('4'):
      key = arcade::api::IEvents::Key::KEY_4;
      break;
    case('5'):
      key = arcade::api::IEvents::Key::KEY_5;
      break;
    case('6'):
      key = arcade::api::IEvents::Key::KEY_6;
      break;
    case('7'):
      key = arcade::api::IEvents::Key::KEY_7;
      break;
    case('8'):
      key = arcade::api::IEvents::Key::KEY_8;
      break;
      case('9'):
      key = arcade::api::IEvents::Key::KEY_9;
      break;
      default:
      key = arcade::api::IEvents::Key::UNKNOWN;
    };
  return key;
}

bool		arcade::libncurse::EventsNcurse::keyPressed(arcade::api::IEvents::Key id) const
{
  if (std::find(_keys.begin(), _keys.end(), id) == _keys.end())
    return false;
  return true;
}
