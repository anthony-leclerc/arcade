/*
** SFMLContext.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/SFMLContext.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:30:31 2017 Anthony LECLERC
// Last update Sun Apr  9 06:55:40 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_SFMLCONTEXT_HPP
# define CPP_ARCADE_SFMLCONTEXT_HPP

# include	<SFML/Graphics.hpp>
# include	"API/IContext.hpp"
# include	"utils/Dimensions.hpp"
# include	"SFMLGraphics.hpp"
# include 	"SFMLEvents.hpp"

namespace arcade {
  namespace sfml {
    class SFMLContext : public api::IContext {
    private:
      arcade::utl::Dimensions _dimensions;
      sf::RenderWindow _window;
      SFMLGraphics _graphics;
      SFMLEvents _events;
      std::string _name;

    public:
      SFMLContext(size_t, size_t);

      /* Interface IContext */
      virtual ~SFMLContext();

      virtual api::IGraphic &getGraphic() override;

      virtual void init() override;

      virtual void stop() override;

      virtual void clear() override;

      virtual void display() override;

      virtual std::string const &getName() const override;

      virtual api::IEvents &getEvents() override;

      virtual ::arcade::utl::Dimensions const &getDimensions() const override { return _dimensions; }

      sf::RenderWindow& getWindow();
    };
  }
}


#endif /* !CPP_ARCADE_SFMLCONTEXT_HPP */
