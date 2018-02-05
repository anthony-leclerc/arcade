/*
** Exceptions.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Exceptions.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 10:13:52 2017 Anthony LECLERC
** Last update Sun Apr  9 14:03:40 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_EXCEPTIONS_HPP
# define CPP_ARCADE_EXCEPTIONS_HPP

# include <exception>

namespace arcade {
  namespace api {
    /**
     * @brief Context specialized exception class (eg. IContext)
     */
    class ContextException : public std::exception {
    public:
      virtual ~ContextException() noexcept {}
      virtual char const *what() const noexcept = 0;
    };

    /**
     * @brief Graphic specialized exception class (eg. IGraphic)
     */
    class GraphicException : public std::exception {
    public:
      virtual ~GraphicException() noexcept {}
      virtual char const *what() const noexcept = 0;
    };

    /**
     * @brief Event specialized exception class (eg. IEvents)
     */
    class EventException : public std::exception {
      virtual ~EventException() noexcept {}
      virtual char const *what() const noexcept = 0;
    };

    /**
     * @brief Game specialized exception class (eg. AGame)
     */
    class GameException : public std::exception {
    public:
      virtual ~GameException() noexcept  {}
      virtual char const *what() const noexcept = 0;
    };
  }
}

#endif /* !CPP_ARCADE_EXCEPTIONS_HPP */
