/*
** AGame.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/AGame.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mars 11 05:11:52 2017 Anthony LECLERC
** Last update Sun Apr  9 14:17:36 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_AGAME_HPP
# define CPP_ARCADE_AGAME_HPP

# include <iostream>
# include <string>
# include "API/IEvents.hpp"
# include "loader/DLInterface.hpp"

/**
 * @brief The namespace arcade contains every useful class for the Arcade project. Every API, utils or exception class in contained in the namespace.
 */
namespace arcade
{

  class IGraphic;

  /**
   * @brief The namespace api contains all the base interfaces for the Arcade projects. The stand for base to every class related to graphics, game logic, events or windowing.
   */
  namespace api {

    /**
     * @brief AGame allows the user to have a class template for the game class base.
     */
    class AGame
    {
    protected:
      /**
       * @brief Pointer to the current graphic interface.
       */

      IGraphic	*graphic;

      /**
       * @brief Game name.
       */
      std::string _name;

    public:
      virtual 		~AGame() {};

    public:
      AGame() : graphic(0) {};

      /**
       * @brief Stocks the current graphic interface in the game.
       */
      void		setGraphicModule(IGraphic *module)
      {
	graphic = module;
      }

      void		setName(std::string const &name)
      {
	_name = name;
      }

      std::string const	&getName() const
      {
	return _name;
      }

      /**
       * @brief reloads sprites and graphic interactions in the game.
       */
      virtual int	reloadSprites() = 0;

      /**
       * @brief Inits the window and the graphic pointer *graphic.
       */
      virtual int	init(IGraphic *graphic) = 0;

      /**
       * @brief Plays a game frame. This function must be called in the mainloop.
       * @param The current event class (eg. IEvents)
       */
      virtual int	play(IEvents const &event) = 0;

      /**
       * @brief Closes the game and clears his datas.
       */
      virtual int	close() = 0;

      /**
       * @brief Restart the game.
       */
      virtual int	restart() = 0;

      /**
       * @brief Gets the current score to display it at game over..
       */
      virtual int	getScore() const = 0;
    };
  }


}


#endif /* !CPP_ARCADE_AGAME_HPP */
