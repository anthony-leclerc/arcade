/*
** OpenGLContext.cpp for arcade in /home/baldas/Prog/repos/tek2/cpp/cpp_arcade/openGL/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Apr  3 16:52:48 2017 Hugo Baldassin
** Last update Sun Apr  9 17:38:32 2017 Sylvain Chaugny
*/

#include	<SFML/Window.hpp>
#include	<SFML/OpenGL.hpp>
#include	<iostream>
#include 	<GL/freeglut.h>
#include 	<memory.h>
#include	"OpenGLGraphic.hpp"
#include	"OpenGLContext.hpp"
#include	"GL/glu.h"

arcade::openGL::OpenGLContext::OpenGLContext(size_t width, size_t height) :
  graphics(width, height, this),
  events(*this),
  name("openGL"),
  hidden(false),
  dimensions(width, height),
  _argv_glut(new char[1])
{
  _argv_glut[0] = 0;
  window.setVerticalSyncEnabled(true);
  window.setActive(true);
}

arcade::api::IGraphic	&arcade::openGL::OpenGLContext::getGraphic()
{
  return graphics;
}

void		arcade::openGL::OpenGLContext::init()
{
  int		i = 1;

  window.create(sf::VideoMode(dimensions.width, dimensions.height), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
  glutInit(&i, &_argv_glut);
  glutInitErrorFunc(ret_func);
  gluOrtho2D(0, window.getSize().x, window.getSize().y, 0);
  window.setVisible(true);
  if (hidden)
    {
      window.popGLStates();
      hidden = false;
    }
}

void		arcade::openGL::OpenGLContext::stop()
{
  window.pushGLStates();
  window.close();
  hidden = true;
}

void		arcade::openGL::OpenGLContext::clear()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void		arcade::openGL::OpenGLContext::display()
{
  glFlush();
  window.display();
}

std::string const &arcade::openGL::OpenGLContext::getName() const
{
  return name;
}

arcade::api::IEvents	&arcade::openGL::OpenGLContext::getEvents()
{
  return events;
}

sf::RenderWindow	&arcade::openGL::OpenGLContext::getWindow()
{
  return window;
}


/*
** TO AVOID GLUT TO EXIT
*/

void			ret_func(const char *str, va_list ap)
{
  static_cast<void>(str);
  static_cast<void>(ap);
  return ;
}


/*
** ENTRY POINTS
*/

extern "C" arcade::api::IContext *entry_point()
{
  return new arcade::openGL::OpenGLContext(1600, 960);
}

extern "C" void delete_point(arcade::api::IContext *mod)
{
  delete mod;
}
