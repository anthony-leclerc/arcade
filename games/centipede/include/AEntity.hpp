/*
** AEntity.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/AEntity.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 17:25:57 2017 Anthony LECLERC
// Last update Fri Apr  7 17:21:29 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_AENTITY_HPP
# define CPP_ARCADE_AENTITY_HPP

#include "API/IEvents.hpp"
#include "API/IGraphic.hpp"
# include "utils/Dimensions.hpp"
#include "utils/Position.hpp"
#include "Grid.hpp"

namespace arcade {
  namespace centipede {
    class AEntity {

    private:
      utl::Position _pos;
      utl::Dimensions _size;
      Grid const& _map;
      arcade::TileType _entityType;
      api::IGraphic *_graphic;

    public:
      AEntity(Grid const& map, api::IGraphic *g);
      AEntity(Grid const& map, api::IGraphic *g, utl::Position const& pos);
      AEntity(Grid const& map, api::IGraphic *g, utl::Position const& pos, utl::Dimensions size);
      AEntity& operator=(AEntity const& c);
      virtual ~AEntity() {}

      void setPosition(utl::Position const& pos);
      utl::Position const& getPosition(void) const ;

      api::IGraphic *getGraphic();
      virtual void resetGraphic(api::IGraphic *g);

      Grid const& getMap() const { return _map; }

      TileType getType() const;
      void setType(TileType type);

      virtual void move() = 0;
      virtual void draw() = 0;
      virtual bool onHit(utl::Position const&) { return false; }
      bool operator==(utl::Position const& pos) const;
      bool operator!=(utl::Position const& pos) const;

      bool operator==(utl::Dimensions const& dims) const;
      bool operator!=(utl::Dimensions const& dims) const;
    };
  }
}


#endif /* !CPP_ARCADE_AENTITY_HPP */
