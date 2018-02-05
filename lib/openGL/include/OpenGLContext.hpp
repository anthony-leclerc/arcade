/*
** OpenGLContext.hpp for arcade in /home/baldas/Prog/repos/tek2/cpp/cpp_arcade/openGL/include
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Apr  3 16:35:54 2017 Hugo Baldassin
** Last update Sun Apr  9 17:37:39 2017 Sylvain Chaugny
*/

#ifndef		OPENGLCONTEXT_HPP_
# define	OPENGLCONTEXT_HPP_

# include	<SFML/Window.hpp>
# include 	<SFML/Graphics/RenderWindow.hpp>
# include	"IContext.hpp"
# include	"IGraphic.hpp"
# include	"IEvents.hpp"
# include	"OpenGLGraphic.hpp"
# include 	"OpenGLEvents.hpp"

namespace	arcade
{
  namespace	openGL
  {
    class		OpenGLGraphic;

    class		OpenGLContext: public arcade::api::IContext {
    public:
      OpenGLContext(size_t width, size_t height);
      ~OpenGLContext() { window.close(); };

      arcade::api::IGraphic	&getGraphic();

      void			init();
      void			stop();
      void			clear();
      void			display();
      ::arcade::utl::Dimensions const &getDimensions() const override { return dimensions; }

      std::string const		&getName() const;
      arcade::api::IEvents	&getEvents();
      sf::RenderWindow		&getWindow();

    private:
      sf::RenderWindow		window;
      OpenGLGraphic		graphics;
      OpenGLEvents		events;
      std::string		name;
      bool			hidden;
      arcade::utl::Dimensions	dimensions;
      char			*_argv_glut;
    };
  }
}

void ret_func(const char *, va_list);

#endif		/* !OPENGLCONTEXT_HPP_ */
