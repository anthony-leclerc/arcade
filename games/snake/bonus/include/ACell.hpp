//
// ACell.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Mar 19 23:02:34 2017 Sylvain Chaugny
// Last update Fri Apr  7 18:34:06 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_ASNAKECELL_HPP_
# define	CPP_ARCADE_ASNAKECELL_HPP_

# include	<cstddef>
# include	"utils/Position.hpp"

namespace	arcade
{
  namespace	snake
  {
    class		ACell
    {
    protected:
      ::arcade::utl::Position		_pos;
      int			_sprite_id;

    public:

      /*
      ** FOR ACELL
      */

      virtual	~ACell() {};

      ::arcade::utl::Position const &getPos() const
      {
	return _pos;
      }

      size_t getPosX() const
      {
	return _pos.x;
      }

      size_t getPosY() const
      {
	return _pos.y;
      }

      void	setPos(::arcade::utl::Position const &pos)
      {
	_pos.x = pos.x;
	_pos.y = pos.y;
      }

      void	setPosX(size_t x)
      {
	_pos.x = x;
      }

      void	setPosY(size_t y)
      {
	_pos.y = y;
      }

      int	getSpriteID() const
      {
	return _sprite_id;
      }

      void	setSpriteID(int id)
      {
	_sprite_id = id;
      }
    };
  };
};

#endif		//CPP_ARCADE_ASNAKECELL_HPP_
