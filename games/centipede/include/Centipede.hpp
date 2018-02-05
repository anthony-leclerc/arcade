/*
** Centipede.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Centipede.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. avr. 08 12:51:42 2017 Anthony LECLERC
// Last update Sun Apr  9 11:20:28 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_CENTIPEDE_HPP
# define CPP_ARCADE_CENTIPEDE_HPP

# include <vector>
#include <list>
#include <algorithm>
#include "Player.hpp"

namespace arcade {
  namespace centipede {

    class CentipedeParts {
    private:
      int _sprite_id;
      api::IGraphic *graphic;
      utl::Position _pos;
      Grid const& _map;

    public:
      CentipedeParts(Grid const& map, api::IGraphic *g, utl::Position const& pos);
      ~CentipedeParts() {}
      CentipedeParts& operator=(CentipedeParts const& s);

      void setSprite(int id);

      void setPosition(utl::Position const& pos);

      utl::Position getPosition() const;

      void resetGraphic(api::IGraphic *g);
      bool operator==(utl::Position const& pos) const;

      void draw();
    };

    class Centipede : public AEntity {
    private:
      Direction _dir;
      Direction _lastDir;
      std::list<CentipedeParts> _parts;
      std::list<Centipede> _others;
      int _spriteBodyID;

    public:
      Centipede(Grid const& grid, api::IGraphic *g);

      Centipede(Grid const& grid, api::IGraphic *g, std::list<CentipedeParts> const& body);
      ~Centipede() {}
      Centipede& operator=(Centipede const&);

      void reloadSprites(api::IGraphic *);

      void setOnMap(Grid& map) const;

      bool isHit(utl::Position const& pos) const;

      bool onHit(utl::Position const& pos);

      void moveThis();

      virtual void move();

      virtual void draw();

    };
  }
}


#endif /* !CPP_ARCADE_CENTIPEDE_HPP */
