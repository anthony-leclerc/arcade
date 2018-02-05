/*
** GraphicsNcurse.cpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Mar 17 17:08:26 2017 Sylvain Chaugny
** Last update Sun Apr  9 17:13:02 2017 Sylvain Chaugny
*/

#include	<cmath>
#include	<sys/ioctl.h>
#include	<unistd.h>
#include	<curses.h>
#include	"GraphicsNcurse.hpp"

arcade::libncurse::GraphicsNcurse::GraphicsNcurse()
{
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &_winsize);
  _dimensions.width = (_winsize.ws_col);
  _dimensions.height = (_winsize.ws_row);
  _texture_tab[arcade::TextureID::WALL] = "#";
  _texture_tab[arcade::TextureID::PLAYER_HEAD] = "o";
  _texture_tab[arcade::TextureID::PLAYER_BODY] = "o";
  _texture_tab[arcade::TextureID::POWERUP] = "*";
  _texture_tab[arcade::TextureID::SHOT] = "|";
  _texture_tab[arcade::TextureID::ENEMY] = "0";
}

arcade::libncurse::GraphicsNcurse::~GraphicsNcurse()
{
}

/*
** FROM IGRAPHICS
*/

int		arcade::libncurse::GraphicsNcurse::loadSprite(arcade::TextureID id,
							      std::string const &file,
							      arcade::utl::Position const &pos,
							      arcade::utl::Dimensions const &dim)
{
  int		size;

  size = _sprite_tab.size();
  if (_texture_tab.find(id) == _texture_tab.end())
    return -1;
  _sprite_tab[size] = _texture_tab[id];
  static_cast<void>(file);
  static_cast<void>(pos);
  static_cast<void>(dim);
  return size;
}

void		arcade::libncurse::GraphicsNcurse::unloadSprites()
{
}

int		arcade::libncurse::GraphicsNcurse::getStrlen(std::string const &str)
{
  return str.length();
}

void		arcade::libncurse::GraphicsNcurse::drawCircle(arcade::utl::Position const &pos,
							      size_t radius,
							      arcade::utl::Color const &color)
{
  static_cast<void>(color);
  static_cast<void>(pos);
  static_cast<void>(radius);
}

void		arcade::libncurse::GraphicsNcurse::drawSprite(arcade::utl::Position const &pos,
							      int id,
							      arcade::utl::Color const &color)
{
  drawText(pos, _sprite_tab[id], color);
}

void		arcade::libncurse::GraphicsNcurse::drawLine(arcade::utl::Position const &from,
							    arcade::utl::Position const &to,
							    arcade::utl::Color const &color)
{
  static_cast<void>(from);
  static_cast<void>(to);
  static_cast<void>(color);
}

void		arcade::libncurse::GraphicsNcurse::drawText(arcade::utl::Position const &pos,
							    std::string const &text,
							    arcade::utl::Color const &color)
{
  int		code;

  code = convertRGBColor(color);
  if (code)
    attron(COLOR_PAIR(code));
  mvprintw(pos.y, pos.x, text.c_str());
  if (code)
    attroff(COLOR_PAIR(code));
}

void		arcade::libncurse::GraphicsNcurse::drawRectangle(arcade::utl::Position const &from,
								 size_t width,
								 size_t height,
								 bool fill,
								 arcade::utl::Color const &color)
{
  arcade::utl::Position	i;
  int		code;

  code = convertRGBColor(color);
  if (code)
    attron(COLOR_PAIR(code));
  i.y = (from.y);
  while (i.y < from.y + static_cast<int>(height))
    {
      i.x = (from.x);
      while (i.x < from.x + static_cast<int>(width))
	{
	  if (fill)
	    mvprintw(i.y, i.x, "*");
	  else
	    {
	      if (i.x == from.x || i.x == from.x + static_cast<int>(width) - 1 || i.y == from.y || i.y == from.y + static_cast<int>(height) - 1)
		mvprintw(i.y, i.x, "*");
	    }
	  i.x = (i.x + 1);
	}
      i.y = (i.y + 1);
    }
  if (code)
    attroff(COLOR_PAIR(code));
}

arcade::utl::Dimensions const &arcade::libncurse::GraphicsNcurse::getDimensions() const
{
  return _dimensions;
}

int		arcade::libncurse::GraphicsNcurse::convertRGBColor(arcade::utl::Color const &color)
{
  int		code;

  code = N_NO_COLOR;
  code = color._color.r == 255 && color._color.g == 0 && color._color.b == 0 ? N_RED : code;
  code = color._color.r == 0 && color._color.g == 255 && color._color.b == 0 ? N_GREEN : code;
  code = color._color.r == 255 && color._color.g == 255 && color._color.b == 0 ? N_YELLOW : code;
  code = color._color.r == 0 && color._color.g == 0 && color._color.b == 255 ? N_BLUE : code;
  code = color._color.r == 255 && color._color.g == 0 && color._color.b == 255 ? N_MAGENTA : code;
  code = color._color.r == 0 && color._color.g == 255 && color._color.b == 255 ? N_CYAN : code;
  code = color._color.r == 255 && color._color.g == 255 && color._color.b == 255 ? N_WHITE : code;
  return code;
}
