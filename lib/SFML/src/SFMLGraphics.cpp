/*
** SFMLGraphics.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/SFMLGraphics.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:36:49 2017 Anthony LECLERC
** Last update Sun Apr  9 17:04:38 2017 Sylvain Chaugny
*/

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include "SFMLGraphics.hpp"
#include "SFMLContext.hpp"

int _bloc_size = 32;

int	arcade::sfml::SFMLGraphics::getStrlen(std::string const &str)
{
  return (str.length() * 18) / 64;
}

int arcade::sfml::SFMLGraphics::loadSprite(arcade::TextureID id,
					   std::string const &file,
					   arcade::utl::Position const &pos,
					   arcade::utl::Dimensions const &dim)
{
  sf::Texture *texture(0);

  texture = new sf::Texture;
  if (!texture->loadFromFile(file.c_str(), sf::IntRect(pos.x, pos.y, dim.width, dim.height)))
    {
      std::cerr << "Error while loading texture in " << file << std::endl;
      return -1;
    }
  if (_textures.find(id) != _textures.end())
    delete _textures[id];
  _textures[id] = texture;
  return id;
}

void arcade::sfml::SFMLGraphics::drawLine(arcade::utl::Position const &from,
					  arcade::utl::Position const &to,
					  arcade::utl::Color const &color)
{
  sf::Color sf_color(color._color.r, color._color.g, color._color.b, color._color.a);
  sf::Vertex line[] = {
      sf::Vertex(sf::Vector2f(from.x * _bloc_size, from.y * _bloc_size), sf_color),
      sf::Vertex(sf::Vector2f(to.x * _bloc_size, to.y * _bloc_size), sf_color)
  };
  _context.getWindow().draw(line, 2, sf::Lines);
}

void
arcade::sfml::SFMLGraphics::drawRectangle(arcade::utl::Position const &from,
					  size_t width, size_t height,
					  bool fill,
					  arcade::utl::Color const &color)
{
  sf::RectangleShape Rect(sf::Vector2f(width * _bloc_size, height * _bloc_size));

  Rect.setPosition(sf::Vector2f(from.x * _bloc_size, from.y * _bloc_size));
  if (fill)
    Rect.setFillColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  else
    Rect.setFillColor(sf::Color(0, 0, 0, 0));
  Rect.setOutlineThickness(1);
  Rect.setOutlineColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  _context.getWindow().draw(Rect);
}

void arcade::sfml::SFMLGraphics::drawCircle(arcade::utl::Position const &pos,
					    size_t radius,
					    arcade::utl::Color const &color)
{
  sf::CircleShape circle(radius);

  circle.setOutlineColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  circle.setPosition(pos.x * _bloc_size, pos.y * _bloc_size);
  _context.getWindow().draw(circle);
}

void arcade::sfml::SFMLGraphics::drawSprite(arcade::utl::Position const &pos,
					    int id,
					    arcade::utl::Color const &color)
{
  sf::Sprite sprite;

  static_cast<void>(color);
  sprite.setTexture(*(_textures[id]));
  sprite.setColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  sprite.setPosition(sf::Vector2f(pos.x * _bloc_size, pos.y * _bloc_size));
  _context.getWindow().draw(sprite);
  sprite.setColor(sf::Color(0, 0, 0, 255));
}

void arcade::sfml::SFMLGraphics::drawText(arcade::utl::Position const &pos,
					  std::string const &text,
					  arcade::utl::Color const &color)
{
  sf::Text Text;
  sf::Font font;

  if (!font.loadFromFile("ressource/arial.ttf"))
    {
      std::cerr << "Error while loading font in drawText()" << std::endl;
      return ;
    }
  Text.setFont(font);
  Text.scale(Text.getScale().x * 0.7, Text.getScale().y * 0.7);
  Text.setString(text);
  Text.setPosition(pos.x * _bloc_size, pos.y * _bloc_size);
  Text.setColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  _context.getWindow().draw(Text);
  Text.setColor(sf::Color(0, 0, 0, 255));
}

arcade::utl::Dimensions const &arcade::sfml::SFMLGraphics::getDimensions() const
{
  return _resized_dimensions;
}

arcade::sfml::SFMLGraphics::SFMLGraphics(arcade::sfml::SFMLContext &_context) :
    _context(_context)
{
  _dimensions.width = _context.getDimensions().width;
  _dimensions.height = _context.getDimensions().height;
  _resized_dimensions.width = _dimensions.width / _bloc_size;
  _resized_dimensions.height = _dimensions.height / _bloc_size;
}

void arcade::sfml::SFMLGraphics::unloadSprites()
{
  for (auto it = _textures.begin(); it != _textures.end(); ++it)
    delete it->second;
}
