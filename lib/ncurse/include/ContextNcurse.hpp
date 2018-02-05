//
// ContextNcurse.hpp for arcade in /home/sylvain/Documents/projets/tek2/C++/cpp_arcade/graphics/ncurse/include
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Fri Mar 17 16:16:02 2017 Sylvain Chaugny
// Last update Sun Apr  9 06:50:26 2017 Sylvain Chaugny
//

#ifndef			CPP_ARCADE_CONTEXTNCURSE_HPP_
# define		CPP_ARCADE_CONTEXTNCURSE_HPP_

# include		<string>
# include		<curses.h>
# include		"API/IContext.hpp"
# include		"API/IEvents.hpp"
# include		"utils/Dimensions.hpp"

namespace		arcade
{
  namespace		libncurse
  {
    class		ContextNcurse : public ::arcade::api::IContext
    {
    private:
      std::string const	_name;
      ::arcade::api::IGraphic	*_graphics;
      ::arcade::api::IEvents	*_events;
      ::arcade::utl::Dimensions	_dimensions;
      SCREEN		*_window;

    public:
      ContextNcurse();
      ~ContextNcurse();

      std::string const	&getName()		const;
      void init()				override;
      void stop()				override;
      ::arcade::api::IGraphic &getGraphic()	override;
      void clear()				override;
      void display()				override;
      ::arcade::utl::Dimensions const &getDimensions() const override { return _dimensions; }

      ::arcade::api::IEvents &getEvents();
    };
  };
};

#endif			//CPP_ARCADE_CONTEXTNCURSE_HPP_
