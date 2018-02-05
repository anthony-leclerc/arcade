//
// BoardCell.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Mar 19 23:07:55 2017 Sylvain Chaugny
// Last update Fri Apr  7 18:38:28 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_BOARDCELL_HPP_
# define	CPP_ARCADE_BOARDCELL_HPP_

# include	"ACell.hpp"

namespace	arcade
{
  namespace	snake
  {
    class		BoardCell : public ACell
    {
    private:
    public:
      BoardCell() {}
      ~BoardCell() {}
    };
  };
};

#endif		//CPP_ARCADE_BOARDCELL_HPP_
