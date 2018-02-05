//
// GraphicsNcurse.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Mar 17 17:05:20 2017 Sylvain Chaugny
// Last update Sat Apr  8 22:23:04 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_GRAPHICSNCURSE_HPP_
# define	CPP_ARCADE_GRAPHICSNCURSE_HPP_

# include	<map>
# include	<vector>
# include	<sys/ioctl.h>
# include	"API/IGraphic.hpp"
# include	"utils/Dimensions.hpp"
# include	"utils/Color.hpp"

namespace	arcade
{
  namespace	libncurse
  {
    enum	eNcurseColorCode
      {
	N_NO_COLOR = 0,
	N_RED,
	N_GREEN,
	N_YELLOW,
	N_BLUE,
	N_MAGENTA,
	N_CYAN,
	N_WHITE
      };

    class	GraphicsNcurse : public ::arcade::api::IGraphic
    {
      typedef std::vector<::arcade::utl::Position>	t_pos_tab;
      typedef t_pos_tab::iterator		t_pos_tab_i;
      typedef std::map<arcade::TextureID, std::string> t_texture_tab;
      typedef std::map<int, std::string> t_sprite_tab;

    private:
      t_pos_tab	_pos_tab;
      ::arcade::utl::Dimensions	_dimensions;
      t_texture_tab	_texture_tab;
      t_sprite_tab	_sprite_tab;
      struct winsize	_winsize;

    public:
      GraphicsNcurse();
      ~GraphicsNcurse();

      int	loadSprite(::arcade::TextureID id, std::string const &file,
			   ::arcade::utl::Position const &position,
			   ::arcade::utl::Dimensions const &dimensions);
      void	unloadSprites();

      void	drawCircle(::arcade::utl::Position const &pos,
			   size_t radius,
			   ::arcade::utl::Color const &color);

      void	drawSprite(::arcade::utl::Position const &pos,
			   int id,
			   ::arcade::utl::Color const &color);

      void	drawLine(::arcade::utl::Position const &from,
			 ::arcade::utl::Position const &to,
			 ::arcade::utl::Color const &color);
      void	drawRectangle(::arcade::utl::Position const &from,
			      size_t width,
			      size_t height,
			      bool fill,
			      ::arcade::utl::Color const &color);
      void	drawText(::arcade::utl::Position const &pos,
			 std::string const &text,
			 ::arcade::utl::Color const &color);

      int	getStrlen(std::string const &str);

      ::arcade::utl::Dimensions const &getDimensions() const;
      int	convertRGBColor(::arcade::utl::Color const &color);
    };
  };
};

#endif		//CPP_ARCADE_GRAPHICSNCURSE_HPP_
