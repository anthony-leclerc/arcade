/*
** SFMLContext.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/SFMLContext.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:30:31 2017 Anthony LECLERC
// Last update Sun Apr  9 06:55:46 2017 Sylvain Chaugny
*/

#include "SFMLContext.hpp"

arcade::sfml::SFMLContext::SFMLContext(size_t width, size_t height) :
  _dimensions(width, height),
  _graphics(*this),
  _events(*this),
  _name("SFML Graphics")
{}

arcade::sfml::SFMLContext::~SFMLContext()
{
  _window.close();
}

arcade::api::IGraphic &arcade::sfml::SFMLContext::getGraphic()
{
  return _graphics;
}

std::string const &arcade::sfml::SFMLContext::getName() const
{
  return _name;
}

arcade::api::IEvents &arcade::sfml::SFMLContext::getEvents()
{
  return _events;
}

void arcade::sfml::SFMLContext::init()
{
  _window.create(sf::VideoMode(_dimensions.width, _dimensions.height), "SFML");
  _window.setVerticalSyncEnabled(true);
  _window.setActive(true);
}

void arcade::sfml::SFMLContext::stop()
{
  _window.close();
}

void arcade::sfml::SFMLContext::clear()
{
  _window.clear(sf::Color::Black);
}

void arcade::sfml::SFMLContext::display()
{
  _window.display();
}

sf::RenderWindow &arcade::sfml::SFMLContext::getWindow()
{
  return _window;
}
