/*
** EntityFactory.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/EntityFactory.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. avr. 08 02:14:13 2017 Anthony LECLERC
** Last update sam. avr. 08 02:14:13 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_ENTITYFACTORY_HPP
# define CPP_ARCADE_ENTITYFACTORY_HPP

# include "AEntity.hpp"

namespace arcade {
  namespace centipede {
    template <typename __interface>
    class EntityFactory {
    public:

      template <typename T>
      __interface *create(utl::Position pos, utl::Dimensions dim)
      {
	return new T(pos, dim);
      }

      template <typename T>
      __interface *create(utl::Position pos)
      {
	return new T(pos);
      }

      template<typename T>
      __interface *create()
      {
	return new T();
      }
    };
  }
}

#endif /* !CPP_ARCADE_ENTITYFACTORY_HPP */
