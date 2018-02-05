/*
** IDIsplayModule.hpp for  in /home/anthony/documents/repository/cpp/cpp_arcade
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Mar  8 16:58:32 2017 Anthony LECLERC
** Last update Sun Apr  9 15:45:06 2017 Sylvain Chaugny
*/

#ifndef ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP
# define ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP

# include "IGraphic.hpp"
#include "IEvents.hpp"
#include "utils/Dimensions.hpp"
#include <string>

namespace arcade {
  namespace api {

    /*
     * @brief The IContext interface provides useful methods for the user. The Icontext method is used as the very base of the Arcade architecture.
     */
    class IContext {
    public:

      virtual ~IContext()
      {}

      /*
       * @brief Get context to draw on -> Send to game to keep window safe
       * @return Context interface to implement (see "IGraphic.hpp")
       */
      virtual IGraphic &getGraphic() = 0;

      /**
       * @brief Initialize context -> open window and specific state for graphic lib
       */
      virtual void init() = 0;

      /**
       * @brief Destroy context
       */
      virtual void stop() = 0;

      /**
       * @brief Clear Context
       */
      virtual void clear() = 0;

      /**
       * @brief Display context
       */
      virtual void display() = 0;

      virtual std::string const &getName() const = 0;

      virtual IEvents &getEvents() = 0;

      /**
       * @brief Gets window dimensions.
       */

      virtual ::arcade::utl::Dimensions const &getDimensions() const = 0;

/*
    /// @brief Get object window from library
    /// @return IWindow Interface implementation of current loaded graphic library
    virtual IWindow *getWindow() = 0;

    /// @brief Pop next event in stack
    /// @return Event object containing next event from current loaded graphic library
    virtual IEvents *pollEvent() = 0;*/

    };
  }
}

#endif /* !ARCADE_BOOTSTRAP_IDISPLAYMODULE_HPP */
