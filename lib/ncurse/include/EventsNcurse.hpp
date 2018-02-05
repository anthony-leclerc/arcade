/*
** EventsNcurse.hpp for arcade in /home/sylvain/Documentss/projets/tek2/C++/cpp_arcade/graphics/ncurse
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 23 14:13:24 2017 Sylvain Chaugny
** Last update Sun Apr  9 17:06:07 2017 Sylvain Chaugny
*/

#ifndef		CPP_ARCADE_EVENTSNCURSE_HPP_
# define	CPP_ARCADE_EVENTSNCURSE_HPP_

# include	<map>
# include	<vector>
# include	"API/IEvents.hpp"

namespace	arcade
{
  namespace	libncurse
  {
    class		EventsNcurse : public ::arcade::api::IEvents
    {
      typedef std::vector<IEvents::Key> t_keys;

    private:

      t_keys _keys;

    public:
      EventsNcurse();
      ~EventsNcurse();

      void	pollEvents() override;
      bool	keyPressed(IEvents::Key id) const;

      IEvents::Key	getCorrespondingKey(int c) const;

      /**
       * @Useless methods for ncurse
       */

      bool	mouseButtonPressed(IEvents::MouseKey id) const
      {
	static_cast<void>(id);
	return false;
      };

      int	getXMousePos() const
      {
	return -1;
      };

      int	getYMousePos() const
      {
	return -1;
      };

      ::arcade::utl::Position getMousePos() const
      {
	return 0;
      }
    };
  };
};

#endif		//CPP_ARCADE_EVENTSNCURSE_HPP_
