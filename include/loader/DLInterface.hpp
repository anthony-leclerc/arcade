/*
** DLInterface.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/DLInterface.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mars 11 06:17:14 2017 Anthony LECLERC
** Last update sam. mars 11 06:17:14 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_DLINTERFACE_HPP
# define CPP_ARCADE_DLINTERFACE_HPP

namespace utl {
  template<typename T>
  class DLInterface_traits
  {
  public:
    typedef T		value;
    typedef value*	pointer;
    typedef value&	reference;
  };

  template<typename T>
  class DLInterface_basic : public DLInterface_traits<T>
  {
  protected:
    DLInterface_basic() {}
    ~DLInterface_basic() {}

  public:

    typedef T		*init_t();
    typedef void	delete_t(T *);

    static const std::string ctor_sym;
    static const std::string dtor_sym;
  };

  template<typename T>
  const std::string DLInterface_basic<T>::ctor_sym = "entry_point";

  template<typename T>
  const std::string DLInterface_basic<T>::dtor_sym = "delete_point";
}

#endif /* !CPP_ARCADE_DLINTERFACE_HPP */
