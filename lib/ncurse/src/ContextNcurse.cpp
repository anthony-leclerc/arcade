//
// ContextNcurse.cpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Mar 17 16:26:28 2017 Sylvain Chaugny
// Last update Sat Mar 25 00:11:25 2017 Sylvain Chaugny
//

#include	<curses.h>
#include	"ContextNcurse.hpp"
#include	"GraphicsNcurse.hpp"
#include	"NcurseExceptions.hpp"
#include	"EventsNcurse.hpp"

arcade::libncurse::ContextNcurse::ContextNcurse() :
  _name("ContextNcurse"),
  _graphics(new GraphicsNcurse()),
  _events(new EventsNcurse()),
  _window(NULL)
{
}

arcade::libncurse::ContextNcurse::~ContextNcurse()
{
  delete _graphics;
  delete _events;
}

std::string const	&arcade::libncurse::ContextNcurse::getName() const
{
  return _name;
}

void			arcade::libncurse::ContextNcurse::init()
{
  if ((_window = newterm(NULL, stdout, stdin)) == NULL)
    throw utl::NcurseException("couldn't initialize window");
   noecho();
  curs_set(FALSE);
  start_color();
  init_pair(N_GREEN, COLOR_GREEN, 0);
  init_pair(N_YELLOW, COLOR_YELLOW, 0);
  init_pair(N_RED, COLOR_RED, 0);
  init_pair(N_CYAN, COLOR_CYAN, 0);
  init_pair(N_MAGENTA, COLOR_MAGENTA, 0);
  init_pair(N_WHITE, COLOR_WHITE, 0);
  init_pair(N_BLUE, COLOR_BLUE, 0);
}

void			arcade::libncurse::ContextNcurse::stop()
{
  endwin();
  delscreen(_window);
  _window = NULL;
}

arcade::api::IGraphic	&arcade::libncurse::ContextNcurse::getGraphic()
{
  return *_graphics;
}

void			arcade::libncurse::ContextNcurse::clear()
{
  erase();
}

void			arcade::libncurse::ContextNcurse::display()
{
  refresh();
}

arcade::api::IEvents	&arcade::libncurse::ContextNcurse::getEvents()
{
  return *_events;
}

/*
** ANCHOR POINTS
*/

extern "C" arcade::api::IContext *entry_point()
{
  return new arcade::libncurse::ContextNcurse;
}

extern "C" void delete_point(arcade::api::IContext *mod)
{
  delete mod;
}
