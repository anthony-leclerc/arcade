/*
** Obstacle.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Obstacle.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. avr. 07 14:38:45 2017 Anthony LECLERC
// Last update Sun Apr  9 11:19:10 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_OBSTACLE_HPP
# define CPP_ARCADE_OBSTACLE_HPP

# include "API/IGraphic.hpp"
#include "utils/Dimensions.hpp"
#include "AEntity.hpp"

namespace arcade {
  namespace centipede {
    class Obstacle : public AEntity {
    private:
      static const utl::Color States[5];
      int _pv;
      int sprite_id;

    public:
      Obstacle(Grid const& map, api::IGraphic *Graphic, utl::Position pos,
               utl::Dimensions dim = utl::Dimensions(1, 1));

      virtual void move();
      void draw();
      bool onHit(utl::Position const& pos);

      virtual void resetGraphic(api::IGraphic *g) override;
    };
  }
}


#endif /* !CPP_ARCADE_OBSTACLE_HPP */
