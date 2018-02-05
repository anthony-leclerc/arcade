//
// ADrawModel.hpp for  in /home/anthony/documents/repository/cpp/cpp_arcade
// 
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.net>
// 
// Started on  Wed Mar  8 16:58:03 2017 Anthony LECLERC
// Last update Wed Mar  8 16:58:14 2017 Anthony LECLERC
//

#ifndef CPP_ARCADE_ADRAWMODEL_HPP
# define CPP_ARCADE_ADRAWMODEL_HPP

# include "../API/Protocol.hpp"

template<typename T>
class ADrawModel {
private:
  IModelView *_view;
public:
  ADrawModel();

  virtual ~ADrawModel();
};

#endif /* CPP_ARCADE_ADRAWMODEL_HPP */
