/*
** IEvents.hpp for  in /home/anthony/documents/repository/cpp/cpp_arcade
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Wed Mar  8 16:58:40 2017 Anthony LECLERC
** Last update Sun Apr  9 14:08:13 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_IEVENTS_HPP
# define	CPP_ARCADE_IEVENTS_HPP

# include	<cstddef>
# include	"utils/Position.hpp"
# include	"API/Protocol.hpp"

namespace	arcade
{
  namespace	api {
    /**
     * @brief The IEvents interface allows the user to interact generically with the input devices (keyboard, mouse) thanks to the Key enum.
     */
    class IEvents {
    public:

      /** Enum for keyboard keys.
       * The enum is an interface to check keyboard event from outside.
       * Enums in the graphics library could be different, so you must manually
       * match all the values to the corresponding ID of this enum.
       */
      enum Key {
	UNKNOWN =	-1, /*!< Unhandled key	**/
	LEFT,		/*!< Left arrow		**/
	RIGHT,		/*!< Right arrow	**/
	UP,		/*!< Up arrow		**/
	DOWN,		/*!< Down arrow		**/
	ESCAPE,		/*!< Escape		**/
	DELETE,		/*!< Backspace		**/
	ENTER,		/*!< Carriage return	**/
	KEY_1,		/*!< Key digit 1	**/
	KEY_2,		/*!< Key digit 2	**/
	KEY_3,		/*!< Key digit 3	**/
	KEY_4,		/*!< Key digit 4	**/
	KEY_5,		/*!< Key digit 5	**/
	KEY_6,		/*!< Key digit 6	**/
	KEY_7,		/*!< Key digit 7	**/
	KEY_8,		/*!< Key digit 8	**/
	KEY_9,		/*!< Key digit 9	**/
	KEY_0,		/*!< Key digit 0	**/
	CTRL,		/*!< Control		**/
	SHIFT,		/*!< Shift 		**/
	ALT,		/*!< Alt		**/
	SPACE,		/*!< Space		**/
	TAB,		/*!< Tabulation		**/
	A,		/*!< A			**/
	B,		/*!< B			**/
	C,		/*!< C			**/
	D,		/*!< D			**/
	E,		/*!< E			**/
	F,		/*!< F			**/
	G,		/*!< G			**/
	H,		/*!< H			**/
	I,		/*!< I			**/
	J,		/*!< J			**/
	K,		/*!< K			**/
	L,		/*!< L			**/
	M,		/*!< M			**/
	N,		/*!< N			**/
	O,		/*!< O			**/
	P,		/*!< P			**/
	Q,		/*!< Q			**/
	R,		/*!< R			**/
	S,		/*!< S			**/
	T,		/*!< T			**/
	U,		/*!< U			**/
	V,		/*!< V			**/
	W,		/*!< W			**/
	X,		/*!< X			**/
	Y,		/*!< Y			**/
	Z,		/*!< Z			**/
	KEYS		/*!< Keys handled count	**/
      };

      enum MouseKey {
	M_UNKNOWN = -1,	   /*!< Unhandled button	**/
	M_BUTTON_1,        /*!< Left mouse button. 	**/
	M_BUTTON_2,        /*!< Right mouse button. 	**/
	M_BUTTON_3,        /*!< Middle mouse button 	**/
	M_BUTTONS	   /*!< Mouse button count 	**/
      };

      virtual ~IEvents()
      {}

      /**
       * @brief Get every event that occured in the previous frame,
       * and refresh internal state of the other events.
       */
      virtual void	pollEvents() = 0;

      /**
       * @brief Return the status of a key from keyboard.
       * @param id Key ID to check.
       * @return Return true if the key if ID "id" is pressed, false otherwise.
       */
      virtual bool	keyPressed(IEvents::Key id) const = 0;

      /**
       * @brief Return the status of a button from mouse.
       * @param id Mouse button ID to check.
       * @return Return true if the button of ID "id" is pressed, false otherwise.
       */
      virtual bool	mouseButtonPressed(IEvents::MouseKey id) const = 0;

      /**
       * @brief Mouse position getter.
       * @return Signed value relative of the screen bottom left corner.
       * Should return -1,-1 if the mouse is outside the screen.
       */
      virtual utl::Position getMousePos() const = 0;
    };
  }
}

#endif /* !CPP_ARCADE_IEVENTS_HPP */
