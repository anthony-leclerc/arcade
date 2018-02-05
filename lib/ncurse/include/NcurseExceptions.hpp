//
// NcurseExceptions.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sat Mar 18 13:28:24 2017 Sylvain Chaugny
// Last update Sat Mar 25 00:07:43 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_NCURSEEXCEPTIONS_HPP_
# define	CPP_ARCADE_NCURSEEXCEPTIONS_HPP_

# include	<exception>

namespace	arcade
{
  namespace	libncurse
  {
    namespace	utl
    {
      /*
      ** Ncurse standard exception
      */

      class		NcurseException : public std::exception
      {
      private:
	char const	*_err;

      public:
	NcurseException(char const *err) noexcept;
	virtual ~NcurseException() noexcept;

	virtual char const *what() const noexcept;
      };
    };
  };
};

#endif		//CPP_ARCADE_NCURSEEXCEPTIONS_HPP_
