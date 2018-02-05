/*
** Framerate.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Framerate.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. avr. 04 10:34:14 2017 Anthony LECLERC
// Last update Sun Apr  9 09:04:27 2017 Sylvain Chaugny
*/

#ifndef CPP_ARCADE_FRAMERATE_HPP
# define CPP_ARCADE_FRAMERATE_HPP

# include <chrono>

namespace arcade {
  class Framerate {
  private:

    double	_frameTime;
    std::chrono::steady_clock _clock;
    std::chrono::steady_clock::time_point _now;
    bool	_action_allowed;
    std::chrono::steady_clock::time_point	_action_time;
    double	_delay;

  public:
    Framerate(double framerate);
    ~Framerate();

    void 	setFramerate(double value);
    void	setDelay(double delay);
    bool	allowAction();
    void	actionAllowed();
    void	waitFrame();
  };
}


#endif /* !CPP_ARCADE_FRAMERATE_HPP */
