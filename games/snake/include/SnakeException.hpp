//
// SnakeException.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sat Apr  8 23:18:16 2017 Sylvain Chaugny
// Last update Sat Apr  8 23:21:46 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_SNAKEEXCEPTION_HPP_
# define	CPP_ARCADE__SNAKEEXCEPTION_HPP_

# include	"API/Exceptions.hpp"

namespace	arcade
{
  namespace	snake
  {
    class	SnakeException : public ::arcade::api::GameException
    {
    private:
      const char	*_except;

    public:
      SnakeException(const char *except) : _except(except) {}
      ~SnakeException() {}

      const char	*what() const noexcept { return _except; }
    };
  };
};

#endif		/* !CPP_ARCADE__SNAKEEXCEPTION_HPP_ */
