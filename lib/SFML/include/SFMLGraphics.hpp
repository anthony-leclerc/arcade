/*
** SFMLGraphics.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/SFMLGraphics.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 21:36:49 2017 Anthony LECLERC
// Last update Sun Apr  9 06:12:10 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_SFMLGRAPHICS_HPP
# define CPP_ARCADE_SFMLGRAPHICS_HPP

# include <map>
# include <SFML/Graphics/Texture.hpp>
# include "API/IGraphic.hpp"
# include "utils/Dimensions.hpp"

namespace arcade {
  namespace sfml {
    class SFMLContext;

    class SFMLGraphics : public api::IGraphic {
    private:

      SFMLContext &_context;
      std::map<int, sf::Texture *> _textures;
      ::arcade::utl::Dimensions _dimensions;
      ::arcade::utl::Dimensions _resized_dimensions;

    public:
      SFMLGraphics(SFMLContext &_context);

      int	getStrlen(std::string const &str);

      virtual int loadSprite(TextureID id, std::string const &file, ::arcade::utl::Position const &pos, ::arcade::utl::Dimensions const &dim) override;

      virtual void drawLine(utl::Position const &from, utl::Position const &to,
			    utl::Color const &color) override;

      virtual void
      drawRectangle(utl::Position const &from, size_t width, size_t height,
		    bool fill, utl::Color const &color) override;

      virtual void drawCircle(utl::Position const &pos, size_t radius,
			      utl::Color const &color) override;

      virtual void
      drawSprite(utl::Position const &pos, int,
		 utl::Color const &color) override;

      virtual void drawText(utl::Position const &pos, std::string const &text,
			    utl::Color const &color) override;

      virtual utl::Dimensions const &getDimensions() const override;

      void	unloadSprites();
    };
  }
}

#endif /* !CPP_ARCADE_SFMLGRAPHICS_HPP */
