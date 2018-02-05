/*
** Dimensions.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/include/utils
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 18 14:17:07 2017 Sylvain Chaugny
** Last update Sun Apr  9 14:23:36 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_DIMENSIONS_HPP_
# define	CPP_ARCADE_DIMENSIONS_HPP_

# include	<cstddef>

namespace	arcade
{
  namespace	utl
  {
    /**
     * @brief The Dimensions class contains the width and the height of an element.
     */
    class	Dimensions
    {
    public:
      /**
       * @brief The width
       */
      size_t	width;

      /**
       * @brief The height
       */
      size_t	height;

      Dimensions(size_t _width = 0, size_t _height = 0) : width(_width), height(_height) {}
      ~Dimensions() {}
    };
  };
};

#endif		//CPP_ARCADE_DIMENSIONS_HPP_
