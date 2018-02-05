//
// NcurseExceptions.cpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sat Mar 18 13:32:02 2017 Sylvain Chaugny
// Last update Sat Mar 25 00:09:09 2017 Sylvain Chaugny
//

#include	"NcurseExceptions.hpp"

/*
** NcurseException
*/

arcade::libncurse::utl::NcurseException::NcurseException(char const *err) noexcept:
  _err(err)
{
}

arcade::libncurse::utl::NcurseException::~NcurseException() noexcept
{
}

char const	*arcade::libncurse::utl::NcurseException::what() const noexcept
{
  return _err;
}
