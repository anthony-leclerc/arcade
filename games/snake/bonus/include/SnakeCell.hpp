//
// SnakeCell.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Mar 19 23:07:55 2017 Sylvain Chaugny
// Last update Tue Apr  4 10:13:26 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_SNAKECELL_HPP_
# define	CPP_ARCADE_SNAKECELL_HPP_

# include	<cstddef>
# include	"ACell.hpp"
# include	"API/IEvents.hpp"

namespace	arcade
{
  namespace	snake
  {
    class		SnakeCell : public ACell
    {
    private:
      bool	_is_head;
      bool	_is_new;
      ::arcade::api::IEvents::Key _direction;

    public:
      SnakeCell();
      ~SnakeCell();

      void	setIsHead(bool is_head);
      bool	getIsHead() const;
      void	setIsNew(bool is_new);
      bool	getIsNew() const;
      ::arcade::api::IEvents::Key getDirection() const;
      void	setDirection(::arcade::api::IEvents::Key);
      void	updatePosition();
    };
  };
};

#endif		//CPP_ARCADE_SNAKECELL_HPP_
