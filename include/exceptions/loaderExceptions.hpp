/*
** loaderExceptions.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/loaderExceptions.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mars 15 00:19:11 2017 Anthony LECLERC
// Last update Fri Mar 17 17:47:06 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_LOADEREXCEPTIONS_HPP
# define CPP_ARCADE_LOADEREXCEPTIONS_HPP

# include <cstdlib>
#include <exception>

namespace utl {

  /*
  ** loaderException
  */

  class loaderException : public std::exception {
  private:
    char const *_err;

  public:
    loaderException(char const *err) noexcept : _err(err)
    {}

    virtual ~loaderException() noexcept
    {}

    virtual char const *what() const noexcept
    { return _err; }
  };

  /*
  ** dlError
  */

  class dlError : public loaderException
  {
  private:
    char const *_dlerror;

  public:
    dlError(char const *err, char const *dlerror) noexcept :
	loaderException(err), _dlerror(dlerror) {}

    virtual ~dlError() noexcept {}

    virtual char const *dlerror() const noexcept { return _dlerror; }
  };

  /*
  ** dlOpenError
  */

  class dlOpenError : public dlError {
  public:
    dlOpenError(char const *err, char const *dlerror) noexcept :
	dlError(err, dlerror)
    {}

    virtual ~dlOpenError() noexcept {}
  };
}
#endif /* !CPP_ARCADE_LOADEREXCEPTIONS_HPP */
