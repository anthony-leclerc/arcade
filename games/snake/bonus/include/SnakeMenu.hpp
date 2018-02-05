//
// SnakeMenu.hpp for arcade in /home/sylvain/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Apr  7 19:13:02 2017 Sylvain Chaugny
// Last update Sat Apr  8 06:16:10 2017 Sylvain Chaugny
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
      bool	_setup;

    public:
      SnakeMenu() { _setup = false; }
      ~SnakeMenu() {}

      void	setGraphic(::arcade::api::IGraphic *graphic)
      {
	_graphic = graphic;
      }

      int	displayMenu(::arcade::api::IEvents const &event);
      int	displaySetup(::arcade::api::IEvents const &event, ::arcade::utl::Dimensions &dim);
      int	displayGameOver(::arcade::api::IEvents const &event, int score);

      bool      isSetupMenuActive() const { return _setup; }
    };
  };
};

#endif		//CPP_ARCADE_SNAKEMENU_HPP_
