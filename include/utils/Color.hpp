/*
 ** Color.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Mar 24 23:26:16 2017 Sylvain Chaugny
** Last update Sun Apr  9 14:26:20 2017 Sylvain Chaugny
*/

#ifndef			CPP_ARCADE_COLOR_HPP_
# define		CPP_ARCADE_COLOR_HPP_

namespace		arcade
{
  /**
   * @brief The namespace utl contains several very useful classes such as Position or Dimensions. The classes contained in utl are used everywhere and allow the user to access every-type data.
   */
  namespace		utl
  {
    /**
     * @brief The Color class permits to custom the drawng color of an element.
     */
    class		Color
    {
    public:
      /**
      * @brief The color union contains the RGBA representation and components of a given color.
      */
      union		color
      {
	struct
	{
	  unsigned char	r;
	  unsigned char	g;
	  unsigned char	b;
	  unsigned char	a;
	};
	unsigned int	color;
      }			_color;
      Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255)
      {
	_color.r = r;
	_color.g = g;
	_color.b = b;
	_color.a = a;
      }
      ~Color() {}
    };
  };
};

#endif			//CPP_ARCADE_COLOR_HPP_
