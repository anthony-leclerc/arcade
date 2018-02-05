/*
** Grid.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Grid.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 17:19:03 2017 Anthony LECLERC
** Last update jeu. avr. 06 17:19:03 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_GRID_HPP
# define CPP_ARCADE_GRID_HPP

# include <vector>
#include "API/Protocol.hpp"

namespace arcade {
  namespace centipede {

    class AEntity;
    class CentipedeParts;

    class Grid {

    private:
      unsigned long _width;
      unsigned long _height;
      unsigned long _posx;
      unsigned long _posy;

      std::vector<arcade::TileType> _map;

    public:
      Grid();
      Grid(unsigned long width, unsigned long height);
      virtual ~Grid() {}

      void setDimensions(unsigned long width, unsigned long height);
      void setPosition(unsigned long posx, unsigned long posy);
      unsigned long getWidth() const { return _width; }
      unsigned long getHeight() const { return _height; }
      unsigned long getPosX() const { return _posx; }
      unsigned long getPosY() const { return _posy; }

      void putEntity(AEntity const *);
      void putEntity(CentipedeParts const *);
      void clear(void);

      arcade::TileType operator()(int x, int y) const;
      arcade::TileType &operator()(int x, int y);

      std::vector<arcade::TileType> const& getMap() const;
    };
  }
}

#endif /* !CPP_ARCADE_GRID_HPP */
