/*
** OpenGLEvents.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/OpenGLEvents.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:44:32 2017 Anthony LECLERC
** Last update Fri Apr  7 14:10:06 2017 Hugo Baldassin
*/

#include 	<iostream>
#include 	"OpenGLContext.hpp"
#include 	"OpenGLEvents.hpp"

arcade::openGL::OpenGLEvents::OpenGLEvents(OpenGLContext &context) :
    _refContext(context)
{}

void arcade::openGL::OpenGLEvents::pollEvents()
{
  sf::Event event;

  std::fill_n(&Mouse[0], M_BUTTONS, false);
  std::fill_n(&KeyPressed[0], KEYS, false);
  while (_refContext.getWindow().pollEvent(event))
  {
    if (event.KeyPressed)
    {
      switch (event.key.code) {
        case sf::Keyboard::A : KeyPressed[api::IEvents::Key::A] = true; break;
        case sf::Keyboard::B : KeyPressed[api::IEvents::Key::B] = true; break;
        case sf::Keyboard::C : KeyPressed[api::IEvents::Key::C] = true; break;
        case sf::Keyboard::D : KeyPressed[api::IEvents::Key::D] = true; break;
        case sf::Keyboard::E : KeyPressed[api::IEvents::Key::E] = true; break;
        case sf::Keyboard::F : KeyPressed[api::IEvents::Key::F] = true; break;
        case sf::Keyboard::G : KeyPressed[api::IEvents::Key::G] = true; break;
        case sf::Keyboard::H : KeyPressed[api::IEvents::Key::H] = true; break;
        case sf::Keyboard::I : KeyPressed[api::IEvents::Key::I] = true; break;
        case sf::Keyboard::J : KeyPressed[api::IEvents::Key::J] = true; break;
        case sf::Keyboard::K : KeyPressed[api::IEvents::Key::K] = true; break;
        case sf::Keyboard::L : KeyPressed[api::IEvents::Key::L] = true; break;
        case sf::Keyboard::M : KeyPressed[api::IEvents::Key::M] = true; break;
        case sf::Keyboard::N : KeyPressed[api::IEvents::Key::N] = true; break;
        case sf::Keyboard::O : KeyPressed[api::IEvents::Key::O] = true; break;
        case sf::Keyboard::P : KeyPressed[api::IEvents::Key::P] = true; break;
        case sf::Keyboard::Q : KeyPressed[api::IEvents::Key::Q] = true; break;
        case sf::Keyboard::R : KeyPressed[api::IEvents::Key::R] = true; break;
        case sf::Keyboard::S : KeyPressed[api::IEvents::Key::S] = true; break;
        case sf::Keyboard::T : KeyPressed[api::IEvents::Key::T] = true; break;
        case sf::Keyboard::U : KeyPressed[api::IEvents::Key::U] = true; break;
        case sf::Keyboard::V : KeyPressed[api::IEvents::Key::V] = true; break;
        case sf::Keyboard::W : KeyPressed[api::IEvents::Key::W] = true; break;
        case sf::Keyboard::X : KeyPressed[api::IEvents::Key::X] = true; break;
        case sf::Keyboard::Y : KeyPressed[api::IEvents::Key::Y] = true; break;
        case sf::Keyboard::Z : KeyPressed[api::IEvents::Key::Z] = true; break;
        case sf::Keyboard::Num0 : KeyPressed[api::IEvents::Key::KEY_0] = true; break;
        case sf::Keyboard::Num1 : KeyPressed[api::IEvents::Key::KEY_1] = true; break;
        case sf::Keyboard::Num2 : KeyPressed[api::IEvents::Key::KEY_2] = true; break;
        case sf::Keyboard::Num3 : KeyPressed[api::IEvents::Key::KEY_3] = true; break;
        case sf::Keyboard::Num4 : KeyPressed[api::IEvents::Key::KEY_4] = true; break;
        case sf::Keyboard::Num5 : KeyPressed[api::IEvents::Key::KEY_5] = true; break;
        case sf::Keyboard::Num6 : KeyPressed[api::IEvents::Key::KEY_6] = true; break;
        case sf::Keyboard::Num7 : KeyPressed[api::IEvents::Key::KEY_7] = true; break;
        case sf::Keyboard::Num8 : KeyPressed[api::IEvents::Key::KEY_8] = true; break;
        case sf::Keyboard::Num9 : KeyPressed[api::IEvents::Key::KEY_9] = true; break;
        case sf::Keyboard::Escape : KeyPressed[api::IEvents::Key::ESCAPE] = true; break;
        case sf::Keyboard::LControl :
        case sf::Keyboard::RControl : KeyPressed[api::IEvents::Key::CTRL] = true; break;
        case sf::Keyboard::LShift :
        case sf::Keyboard::RShift : KeyPressed[api::IEvents::Key::SHIFT] = true; break;
        case sf::Keyboard::LAlt :
        case sf::Keyboard::RAlt : KeyPressed[api::IEvents::Key::ALT] = true; break;
        case sf::Keyboard::Space : KeyPressed[api::IEvents::Key::SPACE] = true; break;
        case sf::Keyboard::Return : KeyPressed[api::IEvents::Key::ENTER] = true; break;
        case sf::Keyboard::BackSpace : KeyPressed[api::IEvents::Key::DELETE] = true; break;
        case sf::Keyboard::Tab : KeyPressed[api::IEvents::Key::TAB] = true; break;
        case sf::Keyboard::Left : KeyPressed[api::IEvents::Key::LEFT] = true; break;
        case sf::Keyboard::Right : KeyPressed[api::IEvents::Key::RIGHT] = true; break;
        case sf::Keyboard::Up : KeyPressed[api::IEvents::Key::UP] = true; break;
        case sf::Keyboard::Down : KeyPressed[api::IEvents::Key::DOWN] = true; break;
        default: break;
      }
      if (event.MouseButtonPressed)
      {
        switch (event.mouseButton.button) {
          case sf::Mouse::Left : Mouse[api::IEvents::MouseKey::M_BUTTON_1] = true; break;
          case sf::Mouse::Right : Mouse[api::IEvents::MouseKey::M_BUTTON_2] = true; break;
          case sf::Mouse::Middle : Mouse[api::IEvents::MouseKey::M_BUTTON_3] = true; break;
          default: break;
        }
      }
    }
  }
}

bool arcade::openGL::OpenGLEvents::keyPressed(arcade::api::IEvents::Key id) const
{
  if (id != UNKNOWN)
    return KeyPressed[id];
  return false;
}

bool arcade::openGL::OpenGLEvents::mouseButtonPressed(
    arcade::api::IEvents::MouseKey id) const
{
  if (id != M_UNKNOWN)
    return Mouse[id];
  return false;
}

arcade::utl::Position arcade::openGL::OpenGLEvents::getMousePos() const
{
  sf::Vector2i mousePos(sf::Mouse::getPosition(_refContext.getWindow()));
  sf::Vector2i WinDim(_refContext.getWindow().getSize());

  if ((mousePos.x < 0 || mousePos.x > WinDim.x) &&
      (mousePos.y < 0 || mousePos.y > WinDim.y))
    return utl::Position(-1, -1);
  return utl::Position(mousePos.x, mousePos.y);
}

