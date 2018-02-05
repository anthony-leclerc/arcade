//
// AxisCell.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Mar 24 11:06:19 2017 Sylvain Chaugny
// Last update Tue Apr  4 10:10:53 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_AXISCELL_HPP_
# define	CPP_ARCADE_AXISCELL_HPP_

# include	"ACell.hpp"
# include	"API/IEvents.hpp"

namespace	arcade
{
  namespace	snake
  {
    class	AxisCell : public ACell
    {
    private:
      ::arcade::api::IEvents::Key _direction;

    public:
      AxisCell() {}
      ~AxisCell() {}

      void	setDirection(::arcade::api::IEvents::Key dir)
      {
	_direction = dir;
      };

      ::arcade::api::IEvents::Key getDirection() const
      {
	return _direction;
      };
    };
  };
};

#endif		/* !CPP_ARCADE_AXISCELL_HPP_ */
