/*
** Framerate.cpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Framerate.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 10:34:14 2017 Anthony LECLERC
// Last update Sun Apr  9 09:12:06 2017 Sylvain Chaugny
*/

#include <iostream>
#include <unistd.h>
#include "Framerate.hpp"

arcade::Framerate::Framerate(double framerate) :
    _frameTime(1.0 / framerate),
    _clock(),
    _now(_clock.now()),
    _action_allowed(true),
    _action_time(_clock.now()),
    _delay(1.0)
{}

arcade::Framerate::~Framerate()
{}

void arcade::Framerate::setFramerate(double value)
{
  _frameTime = 1.0 / value;
}

void arcade::Framerate::setDelay(double delay)
{
  _delay = delay;
}

void arcade::Framerate::waitFrame()
{
  usleep(_frameTime * 1000000);
}

void arcade::Framerate::actionAllowed()
{
  _action_allowed = false;
  _action_time = _clock.now();
}

bool arcade::Framerate::allowAction()
{
  std::chrono::duration<double> time_span;

  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(_clock.now() - _action_time);
  if (time_span.count() >= _delay)
    _action_allowed = true;
  return _action_allowed;
}
