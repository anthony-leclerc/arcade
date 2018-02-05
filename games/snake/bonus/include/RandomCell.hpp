//
// RandomCell.hpp for arcade in /home/sylvain/cpp_arcade/games/snake/include
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sat Apr  8 04:49:02 2017 Sylvain Chaugny
// Last update Sat Apr  8 05:58:42 2017 Sylvain Chaugny
//

#ifndef		CPP_SNAKE_RANDOMCELL_HPP_
# define	CPP_SNAKE_RANDOMCELL_HPP_

namespace	arcade
{
  namespace	snake
  {
    class	RandomCell : public ACell
    {
    public:
      enum	RandomEffect
  	{
	  MINUS_4 = 0,
	  MINUS_2,
	  MINUS_1,
	  PLUS_1,
	  PLUS_2,
	  PLUS_4,
	  NORMAL
	};

      typedef std::map<RandomEffect, int> t_effects_tab;

    private:
      RandomEffect _effect;
      t_effects_tab _effects_tab;
      bool _display;

    public:
      RandomCell()
      {
	setRandomEffect();
	_effects_tab[MINUS_4] = -4;
	_effects_tab[MINUS_2] = -2;
	_effects_tab[MINUS_1] = -1;
	_effects_tab[PLUS_1] = 1;
	_effects_tab[PLUS_2] = 2;
	_effects_tab[PLUS_4] = 4;
	_effects_tab[NORMAL] = 1;
      }

      ~RandomCell() {}

      void	setRandomCoordinates(::arcade::utl::Dimensions const &dim)
      {
	_pos.x = rand() % (dim.width - 2) + 1;
	_pos.y = rand() % (dim.height - 2) + 1;
      };

      void	setRandomEffect()
      {
	_effect = static_cast<RandomEffect>(rand() % (1 + NORMAL));
      }

      int	getEffect() const
      {
	return _effects_tab.at(_effect);
      }

      void	setDisplayable()
      {
	_display = true;
       	_display = (rand() % 3 == 0) ? true : false;
      }

      bool	isDisplayable() const
      {
	return _display;
      }
    };
  };
};

#endif		//CPP_SNAKE_RANDOMCELL_HPP_
