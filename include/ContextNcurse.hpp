//
// ContextNcurse.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Mon Mar 13 19:02:17 2017 Sylvain Chaugny
// Last update Mon Mar 13 19:10:46 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_CONTEXTNCURSE_HPP_
# define        CPP_ARCADE_CONTEXTNCURSE_HPP_

# include	<ncurse.h>
# include	"class/IContext.hpp"

class		ContextNcurse
{
private:
  SCREEN	*_window;

  ContextNcurse(ContextNcurse const &ref);
  ContextNcurse	&operator=(ContextNcurse const &ref);

public:
  ContextNcurse();
  ~ContextNcurse();
};

#endif		/* !CPP_ARCADE_CONTEXTNCURSE_HPP_ */
