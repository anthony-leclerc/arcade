//
// FoodCell.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake/include
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Mar 24 17:43:51 2017 Sylvain Chaugny
// Last update Tue Mar 28 14:01:41 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_FOODCELL_HPP_
# define	CPP_ARCADE_FOODCELL_HPP_

# include	"utils/Dimensions.hpp"
# include	"ACell.hpp"
# include	"API/IEvents.hpp"

namespace	arcade
{
  namespace	snake
  {
    class	FoodCell : public ACell
    {
    public:
      FoodCell() {}
      ~FoodCell() {}

      void	setRandomCoordinates(::arcade::utl::Dimensions const &dim)
      {
	_pos.x = rand() % (dim.width - 2) + 1;
	_pos.y = rand() % (dim.height - 2) + 1;
      };
    };
  };
};

#endif
