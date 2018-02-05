/*
** Player.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/Player.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 18:23:16 2017 Anthony LECLERC
// Last update Sun Apr  9 11:17:56 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_PLAYER_HPP
# define CPP_ARCADE_PLAYER_HPP

# include <iostream>
#include <sstream>
#include "API/IGraphic.hpp"
#include "AEntity.hpp"
#include "Grid.hpp"

namespace arcade {
  namespace centipede {
    enum Direction {
      UP,
      DOWN,
      LEFT,
      RIGHT,
      NONE
    };

    class Player : public AEntity {
    private:
      class playerShot : public AEntity {
      private:
	int _sprite_id;

      public:
	playerShot(Grid const& map, api::IGraphic *graphic);
	~playerShot() {};

	void move();

	bool hit(AEntity& e);

	void draw();

	virtual void resetGraphic(api::IGraphic *g) override;
      };

    private:
      Direction _dir;
      playerShot _shot;
      int _spriteID;

    public:
      Player(Grid const& map, api::IGraphic *graphic);

      ~Player() {}

      void setSprite(int id);

      void setDirection(Direction dir);

      virtual void move();

      virtual void draw();

      bool shotHit(AEntity& e);

      utl::Position const& getShotPosition() const;

      void shot();

      virtual void resetGraphic(api::IGraphic *g) override;
    }; // class Player<T>
  } // namespace centipede
} // namespace arcade


#endif /* !CPP_ARCADE_PLAYER_HPP */
