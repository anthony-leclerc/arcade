/*
** GameManager.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/GameManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. avr. 06 17:07:23 2017 Anthony LECLERC
// Last update Sun Apr  9 11:22:47 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_GAMEMANAGER_HPP
# define CPP_ARCADE_GAMEMANAGER_HPP

# include <vector>
#include "API/IGraphic.hpp"
#include "API/AGame.hpp"
#include "Player.hpp"
#include "Centipede.hpp"
#include "Obstacle.hpp"

namespace arcade {
  namespace centipede {

    class GameManager : public api::AGame {
    private:
      Player *_player;
      Centipede *_ennemy;
      std::vector<AEntity *> _obstacles;

      Grid _map;

      int _score;

      static unsigned long const BoardWidth;
      static unsigned long const BoardHeight;
    public:

      GameManager();
      ~GameManager();

      void setMap(unsigned long width, unsigned long height);
      void gameDataInit(unsigned long width, unsigned long height);

      static Direction getDirection(api::IEvents const& e);

      virtual int init(api::IGraphic *gr) override;
      void refreshMap();

      virtual int play(api::IEvents const &event);

      int update();
      void getInputs(api::IEvents const& event);
      void display();
      virtual int reloadSprites();

      virtual int close();

      virtual int restart();

      virtual int getScore() const;

      Player& getPlayer() { return *_player; }
      Centipede& getCentipede() { return *_ennemy; }
      std::vector<AEntity *> &getObstacles() { return _obstacles; }
      Grid &getMap() { return _map; }
    };
  }
}


#endif /* !CPP_ARCADE_GAMEMANAGER_HPP */
