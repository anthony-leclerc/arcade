/*
** SFMLEvents.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/SFMLEvents.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:44:32 2017 Anthony LECLERC
// Last update Sun Apr  9 08:46:37 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_SFMLEVENTS_HPP
# define CPP_ARCADE_SFMLEVENTS_HPP

# include "API/IEvents.hpp"


namespace arcade {
  namespace sfml {

    class SFMLContext;

    class SFMLEvents : public api::IEvents {
    private:


      SFMLContext &_refContext;

      bool KeyPressed[api::IEvents::Key::KEYS];
      bool Mouse[api::IEvents::MouseKey::M_BUTTONS];

    public:
      SFMLEvents(SFMLContext &context);
      virtual void pollEvents() override;

      virtual bool keyPressed(Key id) const override;

      virtual bool mouseButtonPressed(MouseKey id) const override;

      virtual utl::Position getMousePos() const override;
    };
  }
}

#endif /* !CPP_ARCADE_SFMLEVENTS_HPP */
