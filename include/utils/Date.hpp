/*
** Date.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Apr  9 10:11:03 2017 Sylvain Chaugny
** Last update Sun Apr  9 15:25:17 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_DATE_HPP_
# define	CPP_ARCADE_DATE_HPP_

# include	<ctime>
# include	<string>

namespace	arcade
{
  namespace	utl
  {
    /**
    * @brief The Date class allows the user to use a formatted string representing the current date with the current hour.
    */
    class	Date
    {
    private:
      std::string _str;
      time_t	_time;

    public:
      Date() : _time(time(NULL)) { _str = ctime(&_time); }
      ~Date() {}

      /**
       * @brief Gets formetted date string from the ctime function (C)
       */
      std::string getFormattedData()
      {
	return _str;
      }
    };
  };
};

#endif		//CPP_ARCADE_DATE_HPP_
