/*
** DLLoader.hpp for  in /home/anthony/documents/repository/cpp/cpp_arcade
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Mon Mar  6 15:26:39 2017 Anthony LECLERC
** Last update Sun Apr  9 17:22:22 2017 Sylvain Chaugny
*/

#ifndef ARCADE_BOOTSTRAP_DLLOADER_HPP
# define ARCADE_BOOTSTRAP_DLLOADER_HPP

# include <dlfcn.h>
#include <iostream>
#include <sstream>
#include "loader/DLInterface.hpp"
#include "exceptions/loaderExceptions.hpp"


#include <cstring>

namespace utl {
  template<typename T, template <typename> class _loader = DLInterface_basic>
  class DLLoader {
  private:

    void	*_handler;
    typedef	_loader<T>			Loader;
    typedef	typename Loader::init_t		ctor;
    typedef	typename Loader::delete_t	dtor;
    typedef	typename Loader::pointer	pointer;

    ctor *_instance_ctor;
    dtor *_instance_dtor;

    pointer instance;

    std::string _file;

    template<typename U>
    U *loadFunction(const char *symbolName)
    {
      U *function;
      function = (U *)dlsym(_handler, symbolName);
      if (!function)
	{
	  std::stringstream err;
	  err << "Failed to load symbol: [" << symbolName << "]:";
	  throw utl::dlError(std::string(err.str().c_str()).c_str(), std::string(dlerror()).c_str());
	}
      return function;
    }

    void delete_instance()
    {
      if (_instance_dtor)
      {
	_instance_dtor(instance);
      }
    }

  public:
    DLLoader() : _handler(0), _instance_ctor(NULL), _instance_dtor(NULL), instance(0) {}

    DLLoader(DLLoader const& other) = delete;
    DLLoader& operator=(DLLoader const& other) = delete;

    DLLoader(DLLoader &&other) :
	_handler(other._handler),
	_instance_ctor(other._instance_ctor),
	_instance_dtor(other._instance_dtor),
	instance(other.instance),
	_file(other._file)
    {
      other._handler = 0;
      other._instance_ctor = 0;
      other._instance_dtor = 0;
      other.instance = 0;
      other._file = "";
    }

    DLLoader& operator=(DLLoader &&other)
    {
	if (this != &other)
	{
	  _handler = other._handler;
	  _instance_ctor = other._instance_ctor;
	  _instance_dtor = other._instance_dtor;
	  instance = other.instance;
	  _file = other._file;
	  other._handler = 0;
	  other._instance_ctor = 0;
	  other._instance_dtor = 0;
	  other.instance = 0;
	  other._file = "";
	}
	return (*this);
    }

    int load(char const *libname) {
      try
	{
	  _handler = dlopen(libname, RTLD_NOW | RTLD_LOCAL);
	  if (!_handler)
	    {
	      std::stringstream err;
	      err << "Failed to load library: [" << libname << "]:";
	      throw utl::dlOpenError(std::string(err.str().c_str()).c_str(), std::string(dlerror()).c_str());
	    }
	  _instance_ctor = loadFunction<ctor>(Loader::ctor_sym.c_str());
	  _instance_dtor = loadFunction<dtor>(Loader::dtor_sym.c_str());
	}
      catch (utl::dlOpenError const& e)
	{
	  std::cerr << "DLloader error: " << e.what() << " : " << e.dlerror() <<std::endl;
	  return 1;
	}
      catch (utl::dlError const& e)
	{
	  std::cerr << "DLLoader error: " << e.what() << " : " << e.dlerror() << std::endl;
	  std::cerr << "Closing library..." << std::endl;
	  dlclose(_handler);
	  _handler = NULL;
	  return 1;
	}
      _file = libname;
      return 0;
    }

    inline std::string const& getFileName() const
    { return _file; }

    pointer getInstance() {
      if (_instance_ctor)
      {
	if (!instance)
	  instance = _instance_ctor();
	return instance;
      }
      else
      {
	std::cerr
	    << "Error: Can't construct instance, entry point is not loaded."
	    << std::endl;
	return 0;
      }
    }

    void unload() {
      delete_instance();
      if (_handler)
	dlclose(_handler);
      _handler = 0;
      _file = "";
    }

    virtual ~DLLoader() {
      unload();
    }
  };
} // namespace utl

#endif /* !ARCADE_BOOTSTRAP_DLLOADER_HPP */
