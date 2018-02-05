//
// OpenGLGraphic.cpp for arcade in /home/baldas/Prog/repos/tek2/cpp/cpp_arcade/openGL/src
//
// Made by Hugo Baldassin
// Login   <baldas@epitech.net>
//
// Started on  Tue Apr  4 16:25:57 2017 Hugo Baldassin
// Last update Sun Apr  9 08:43:50 2017 Sylvain Chaugny
//

#include 	<GL/gl.h>
#include	<cmath>
#include	<iostream>
#include	<GL/freeglut.h>
#include 	<SFML/Graphics/Texture.hpp>
#include	"OpenGLGraphic.hpp"
#include 	"OpenGLContext.hpp"

int _bloc_size = 32;

arcade::openGL::OpenGLGraphic::OpenGLGraphic(size_t _width, size_t _height,
					     OpenGLContext *_context):
  context(_context),
  dimensions(_width, _height),
  resized_dimensions(_width / _bloc_size, _height / _bloc_size)
{
}

int arcade::openGL::OpenGLGraphic::getStrlen(std::string const &str)
{
  return (str.length() * 18) / 64;
}

void arcade::openGL::OpenGLGraphic::drawLine(arcade::utl::Position const &from,
					     arcade::utl::Position const &to,
					     arcade::utl::Color const &color)
{
  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  glBegin(GL_LINES);
  glVertex2i(from.x, from.y);
  glVertex2i(to.x, to.y);
  glEnd();
  glColor4ub(255, 255, 255, 255);
}

void arcade::openGL::OpenGLGraphic::drawRectangle(arcade::utl::Position const &from,
						  size_t width,
						  size_t height, bool fill,
						  arcade::utl::Color const &color)
{
  arcade::utl::Position tmp_from(from.x * _bloc_size, from.y * _bloc_size);
  arcade::utl::Position tmp_to(tmp_from.x, tmp_from.y);

  if (fill)
    {
      tmp_to.x += width * _bloc_size;
      tmp_to.y += height * _bloc_size;
      glRectf(tmp_from.x, tmp_from.y, tmp_to.x, tmp_to.y);
    }
  else
    {
      tmp_to.x += width * _bloc_size;

      checkPosition(tmp_to);
      checkPosition(tmp_from);
      drawLine(tmp_from, tmp_to, color);

      tmp_to.x -= width * _bloc_size;
      tmp_to.y += height * _bloc_size;
      checkPosition(tmp_to);
      drawLine(tmp_from, tmp_to, color);

      tmp_from.x = tmp_to.x;
      tmp_from.y = tmp_to.y;
      tmp_to.x += width * _bloc_size;

      checkPosition(tmp_to);
      checkPosition(tmp_from);
      drawLine(tmp_from, tmp_to, color);

      tmp_from.x += width * _bloc_size;
      tmp_from.y -= height * _bloc_size;

      checkPosition(tmp_to);
      checkPosition(tmp_from);
      drawLine(tmp_from, tmp_to, color);
    }
  glColor4ub(255, 255, 255, 255);
}

void arcade::openGL::OpenGLGraphic::checkPosition(arcade::utl::Position &pos)
{
  if (pos.x <= 0)
    pos.x = 1;
  if (pos.y <= 0)
    pos.y = 1;
  if (pos.x >= static_cast<int>(dimensions.width))
    pos.x = dimensions.width - 1;
  if (pos.y >= static_cast<int>(dimensions.height))
    pos.y = dimensions.height - 1;
}

void arcade::openGL::OpenGLGraphic::drawCircle(arcade::utl::Position const &pos,
					       size_t radius,
					       arcade::utl::Color const &color)
{
  float delta_theta = 0.01;

  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  glBegin(GL_POLYGON);
  for(float angle = 0; angle < 2 * M_PI; angle += delta_theta)
    glVertex2f(pos.x + radius*cos(angle), pos.y + radius*sin(angle));
  glEnd();
}

void arcade::openGL::OpenGLGraphic::drawSprite(utl::Position const &pos, int id,
					       utl::Color const &color)
{
  sf::Sprite sprite;

  sprite.setColor(sf::Color(color._color.r, color._color.g, color._color.b, color._color.a));
  sprite.setTexture(*(textures[id]));
  sprite.setPosition(sf::Vector2f(pos.x * _bloc_size, pos.y * _bloc_size));
  context->getWindow().pushGLStates();
  context->getWindow().draw(sprite);
  context->getWindow().popGLStates();
  glFlush();
  sprite.setColor(sf::Color(0, 0, 0, 255));
}

void arcade::openGL::OpenGLGraphic::drawText(arcade::utl::Position const &pos,
					     std::string const &text,
					     arcade::utl::Color const &color)
{
  const unsigned char *utext = reinterpret_cast<const unsigned char *>(text.c_str());

  glRasterPos2i(pos.x * _bloc_size, pos.y * _bloc_size);
  context->getWindow().pushGLStates();
  glColor4ub(color._color.r, color._color.g, color._color.b, color._color.a);
  context->getWindow().popGLStates();
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, utext);
  context->getWindow().pushGLStates();
  glColor4ub(0, 0, 0, 255);
  context->getWindow().popGLStates();
}

arcade::utl::Dimensions const &arcade::openGL::OpenGLGraphic::getDimensions() const
{
  return resized_dimensions;
}

int arcade::openGL::OpenGLGraphic::loadSprite(TextureID id, std::string const &file,
					      utl::Position const &pos,
					      utl::Dimensions const &dimensions)
{
  sf::Texture *texture = new sf::Texture();

  if (textures.size() && textures.find(id) != textures.end())
    return id;
  if (!texture->loadFromFile(file.c_str(), sf::IntRect(pos.x, pos.y, dimensions.width, dimensions.height)))
  {
    std::cerr << "Error while loading texture in " << file << std::endl;
    return -1;
  }
  sf::Texture::bind(texture);
  textures.insert(std::pair<int, sf::Texture *>(id, texture));
  return id;
}

void arcade::openGL::OpenGLGraphic::unloadSprites()
{
  for (auto it = textures.begin(); it != textures.end(); ++it)
    delete it->second;
}
