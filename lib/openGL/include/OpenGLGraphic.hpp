//
// OpenGLGraphic.hpp for arcade in /home/baldas/Prog/repos/tek2/cpp/cpp_arcade/openGL/include
//
// Made by Hugo Baldassin
// Login   <baldas@epitech.net>
//
// Started on  Tue Apr  4 16:11:19 2017 Hugo Baldassin
// Last update Sun Apr  9 01:34:34 2017 Sylvain Chaugny
//

#ifndef		OPENGLGRAPHIC_HPP_
# define	OPENGLGRAPHIC_HPP_

# include 	<map>
# include	<vector>
# include 	<SFML/Graphics/Sprite.hpp>
# include	<SFML/Graphics/Texture.hpp>
# include	"IGraphic.hpp"

namespace arcade
{
  namespace openGL
  {
    class OpenGLContext;

    class OpenGLGraphic: public arcade::api::IGraphic {
    public:
      OpenGLGraphic(size_t _width, size_t _height, OpenGLContext *_context);
      ~OpenGLGraphic() {};

      int	getStrlen(std::string const &str);

      int 	loadSprite(TextureID id, std::string const &file,
			    utl::Position const &pos,
			    utl::Dimensions const &dimensions);
      void	unloadSprites();
      void 	drawLine(arcade::utl::Position const &from,
			 arcade::utl::Position const &to,
			 arcade::utl::Color const &color);
      void 	drawRectangle(arcade::utl::Position const &from, size_t width,
			      size_t height, bool fill,
			      arcade::utl::Color const &color);
      void 	drawCircle(arcade::utl::Position const &pos, size_t radius,
			   arcade::utl::Color const &color);
      void 	drawSprite(arcade::utl::Position const &pos,
			   int texture_id,
			   arcade::utl::Color const &color);
      void 	drawText(arcade::utl::Position const &pos, std::string const &text,
			 arcade::utl::Color const &color);
      arcade::utl::Dimensions const &getDimensions() const;

      void	checkPosition(arcade::utl::Position &pos);

    private:
      OpenGLContext 			*context;
      arcade::utl::Dimensions 		dimensions;
      arcade::utl::Dimensions 		resized_dimensions;
      std::map<int, sf::Texture*>	textures;
    };
  }
}

#endif		/* !OPENGLGRAPHIC_HPP_ */
