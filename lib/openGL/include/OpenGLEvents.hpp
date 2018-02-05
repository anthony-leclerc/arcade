/*
** OpenGLEvents.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/OpenGLEvents.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:44:32 2017 Anthony LECLERC
// Last update Fri Apr  7 14:05:30 2017 Hugo Baldassin
*/

#ifndef CPP_ARCADE_OPENGLEVENTS_HPP
#define CPP_ARCADE_OPENGLEVENTS_HPP

#include "API/IEvents.hpp"


namespace arcade {
  namespace openGL {

    class OpenGLContext;

    class OpenGLEvents : public api::IEvents {
    private:


      OpenGLContext &_refContext;

      bool KeyPressed[api::IEvents::Key::KEYS];
      bool Mouse[api::IEvents::MouseKey::M_BUTTONS];

    public:
      OpenGLEvents(OpenGLContext &context);
      virtual void pollEvents() override;

      virtual bool keyPressed(Key id) const override;

      virtual bool mouseButtonPressed(MouseKey id) const override;

      virtual utl::Position getMousePos() const override;
    };
  }
}


#endif /* !CPP_ARCADE_OPENGLEVENTS_HPP */
