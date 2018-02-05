//
// SnakeMenu.hpp for arcade in /home/sylvain/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Apr  7 19:13:02 2017 Sylvain Chaugny
// Last update Fri Apr  7 21:03:10 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_SNAKEMENU_HPP_
# define	CPP_ARCADE_SNAKEMENU_HPP_

# include	<string>
# include	"API/IEvents.hpp"
# include	"API/IGraphic.hpp"
# include	"utils/Dimensions.hpp"

namespace	arcade
{
  namespace	snake
  {
    class	SnakeMenu
    {
    private:
      ::arcade::api::IGraphic *_graphic;

    public:
      SnakeMenu() {}
      ~SnakeMenu() {}

      void	setGraphic(::arcade::api::IGraphic *graphic)
      {
	_graphic = graphic;
      }

      int	displayMenu(::arcade::api::IEvents const &event);
      int	displayGameOver(::arcade::api::IEvents const &event, int score);
    };
  };
};

#endif		/* !CPP_ARCADE_SNAKEMENU_HPP_ */
