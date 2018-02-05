/*
** Position.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/include/utils
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 18 14:17:07 2017 Sylvain Chaugny
** Last update Sun Apr  9 14:25:05 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_POSITION_HPP_
# define	CPP_ARCADE_POSITION_HPP_

# include	<cstddef>

namespace	arcade
{
  namespace	utl
  {
    /**
     * @brief The Position class contains the x and y position of an element.
     */
    class	Position
    {
    public:
      /**
       * @brief The x position.
       */
      int	x;

      /**
       * @brief The y position.
       */
      int	y;

      Position(int _x = 0, int _y = 0) : x(_x), y(_y) {}
      ~Position() {}
    };
  };
};

#endif		//CPP_ARCADE_POSITION_HPP_
