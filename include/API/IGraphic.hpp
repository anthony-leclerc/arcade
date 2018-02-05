/*
** IContext.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/IContext.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mars 13 11:19:36 2017 Anthony LECLERC
** Last update Sun Apr  9 14:15:58 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_IGRAPHIC_HPP
# define	CPP_ARCADE_IGRAPHIC_HPP

# include	<string>
# include	<cstddef>
# include	"utils/Position.hpp"
# include	"utils/Dimensions.hpp"
# include	"utils/Color.hpp"

namespace arcade {
  /**
   * @brief The TextureID enum permits a quick texture recognition by the graphics classes loading methods. It is used to identify a texture and to map it in memory.
   */
  enum		TextureID
    {
      WALL = 1,
      PLAYER_HEAD,
      PLAYER_BODY,
      SHOT,
      ENEMY,
      POWERUP
    };

  namespace api {
    /**
     * @brief The IGraphic interface is the base of the graphics part of the Arcade project. It allows to load sprites and textures, draw shapes and text...
     This interface is contained into the Context classes.
    */
    class IGraphic {
    public:
      virtual ~IGraphic() {}

      /**
       * @brief Open an image file and load it as a sprite associated with an ID.
       * @param id ID of the texture to match with the sprite when called by drawSprite.
       * @param file Relative or complete file for file to load.
       * @return true if the sprite has been correctly loaded, false otherwise.
       */
      virtual int loadSprite(TextureID id, std::string const &file, utl::Position const &pos, utl::Dimensions const &dimensions) = 0;

      /**
       * @brief Unload the stocked sprites. Useful method while quitting or restarting the game.
       */
      virtual void unloadSprites() = 0;

      /**
       * @brief Gets thr length of the string passed in parameter, knowing the pixel size of each letter.
       * @param str string to count
       */
      virtual int getStrlen(std::string const &str) = 0;

      /**
       * @brief Draw line on screen
       * @param from Origin position
       * @param to Destination Position
       * @param color Color of the line
       */
      virtual void drawLine(utl::Position const &from, utl::Position const &to, utl::Color const &color) = 0;

      /**
       * @brief Draw rectangle on screen
       * @param from Origin position
       * @param width rectangle width
       * @param height rectangle height
       * @param fill is the rectangle must be filled or not
       * color Color of the rectangle
       */
      virtual void drawRectangle(utl::Position const &from, size_t width, size_t height, bool fill, utl::Color const &color) = 0;

      /**
       * @brief Draw circle on screen
       * @param pos center position
       * @param radius circle radius
       * @param color of the circle
       */
      virtual void drawCircle(utl::Position const &pos, size_t radius, utl::Color const &color) = 0;

      /**
       * @brief Draw sprite on screen
       * @param pos sprite upper-left corner position
       * @param int sprite ID
       * @param color of the sprite
       */
      virtual void drawSprite(utl::Position const &pos, int id, utl::Color const &color) = 0;

      /**
       * @brief Draw text on screen
       * @param pos sprite upper-left corner position
       * @param text the text to print
       * @param color of the text
       */
      virtual void drawText(utl::Position const &pos, std::string const &text, utl::Color const &color) = 0;
      virtual utl::Dimensions const &getDimensions() const = 0;
    };
  }
}

#endif /* !CPP_ARCADE_IGRAPHIC_HPP */
