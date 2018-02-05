/*
** DLLoaderManager.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/DLLoaderManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mars 11 12:52:53 2017 Anthony LECLERC
// Last update Fri Mar 17 21:34:49 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_DLLOADERMANAGER_HPP
# define CPP_ARCADE_DLLOADERMANAGER_HPP

# include <algorithm>
#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include "loader/DLLoader.hpp"

class DynlibExtParser {
public:
  bool operator()(char const *_name) const
  {
    std::string name(_name);

    if (name[0] ==  '.' || name.size() < 3)
      return false;
    return (name.find(".so", name.size() - 3) != std::string::npos);
  }
};

/*
 * \brief Load all libraries needed by the programm with dlopen/dlsym
 * All libs are contained within the vector _libs and can be accessed via iterators
 * Return values must be checked in case an error occurs during loading
 */
namespace utl {
  template<typename T, typename Loader = utl::DLLoader<T, DLInterface_basic>>
  class DLLoaderManager {
  public:

    typedef typename std::vector<Loader> Loaders;
    typedef typename Loaders::iterator iterator;
    typedef typename Loaders::const_iterator const_iterator;

  private:
    std::string _folder;
    Loaders _libs;

  public:
    DLLoaderManager() : _folder(), _libs() {}

    ~DLLoaderManager() {
      removeLibraries();
    };

    /*
     * \brief iterator for Libraries -> from std::vector
     */
    iterator begin() 			{ return _libs.begin(); }
    const_iterator begin() const	{ return _libs.begin(); }
    iterator end()			{ return _libs.end(); }
    const_iterator end() const 		{ return _libs.end(); }

    /*
     * \brief Load library "file", then add it vector _libs
     *
     * \param file	Absolute or relative path to file
     * \return 0 if ok, 1 if error
     */
    int loadLibrary(std::string const& file)
    {
      Loader libraryLoad;

      std::cout << "Lib path: " << file << std::endl;
      if (std::none_of(_libs.begin(), _libs.end(),
		       [&file](Loader const& it) {
			   std::cout << "Loader file: " << it.getFileName() << " Loaded: " << file << std::endl;
			   return (it.getFileName() == file);
		       }))
      {
	if (libraryLoad.load(file.c_str()) == 1)
	{
	  std::cerr << "Failed to load lib: " << file << "." << std::endl;
	  return 1;
	}
	_libs.push_back(std::move(libraryLoad));
	return 0;
      }
      std::cout << "Exists already" << std::endl;
      return 1;
    }

    /*
     * \brief Load all lib in the directory path
     * \tparam U File name parser
     *
     * \param	path	File name
     * \return Error status, 0 if ok
     */
    template<typename U = DynlibExtParser>
    int loadLibraries(char const *path) {

      DIR *directory;
      struct dirent *file;
      U	parser;

      // Open directory "path" and load every file matching pattern defined by "parser"
      directory = opendir(path);
      if (directory == NULL)
	{
	  // Throw error here
	  return 1;
	}
      file = readdir(directory);
      while (file)
	{
	  if (file->d_type == DT_CHR || file->d_type == DT_REG)
	    {
	      if (parser(&file->d_name[0]))
		{
		  std::string filepath(path);

		  // Add folder path to the file name
		  filepath.append(file->d_name);
		  loadLibrary(filepath);
		}
	    }

	  // Process next file
	  file = readdir(directory);
	}
      if (size() == 0)
      {
	std::cerr << "Error: no lib has been opened." << std::endl;
	return 1;
      }
      closedir(directory);
      return 0;
    }

    /*
     * \brief Unload the library pointed by the iterator and remove it from _libs
     * \param library	iterator to the library to be removed
     */
    void removeLibrary(iterator& library)
    {
      _libs.erase(library);
    }

    void removeLibraries()
    {
      _libs.erase(_libs.begin(), _libs.end());
    }

    void removeLibraries(iterator begin, iterator end)
    {
      _libs.erase(begin, end);
    }

    /*
     * if size == 0, then no library have been loaded
     */
    size_t size() const
    {
      return _libs.size();
    }
  };
}

#endif /* !CPP_ARCADE_DLLOADERMANAGER_HPP */
