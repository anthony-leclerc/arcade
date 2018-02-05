/*
** MouliInterface.hpp for cpp_arcade in /home/anthony/repository/cpp_arcade/MouliInterface.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. avr. 09 08:54:56 2017 Anthony LECLERC
** Last update dim. avr. 09 08:54:56 2017 Anthony LECLERC
*/

#ifndef CPP_ARCADE_MOULIINTERFACE_HPP
#define CPP_ARCADE_MOULIINTERFACE_HPP

#include "API/Protocol.hpp"
#include "GameManager.hpp"

namespace arcade {
  class MouliInterface {
  private:
    centipede::GameManager game;
    uint16_t _currCommand;
    WhereAmI *_me;
    GetMap *_map;
  public:

    MouliInterface();
    ~MouliInterface();

    void convertPosition(utl::Position const &pos);
    void convertMap(std::vector<TileType> const& map);
    bool getCommand();
    void makeCommand(CommandType command);

    template<typename T>
    void writeData(T const& e)
    {
      std::cout.write(reinterpret_cast<char const *>(e), sizeof(T));
    }

  };

  template<>
  inline void MouliInterface::writeData(WhereAmI const& me) {
    std::cout.write(reinterpret_cast<char const *>(&me), sizeof(WhereAmI) + sizeof(Position));
  }

  template<>
  inline void MouliInterface::writeData(GetMap const& map) {
    std::cout.write(reinterpret_cast<char const *>(&map), sizeof(GetMap) + (map.height * map.width * sizeof(TileType)));
  }

}


#endif //CPP_ARCADE_MOULIINTERFACE_HPP
