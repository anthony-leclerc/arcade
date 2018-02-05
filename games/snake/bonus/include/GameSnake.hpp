//
// GameSnake.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Mar 19 22:59:44 2017 Sylvain Chaugny
// Last update Sun Apr  9 10:57:08 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_GAMESNAKE_HPP_
# define	CPP_ARCADE_GAMESNAKE_HPP_

# include	<vector>
# include	<map>
# include	"API/AGame.hpp"
# include	"API/IContext.hpp"
# include	"API/IGraphic.hpp"
# include	"API/IEvents.hpp"
# include	"ACell.hpp"
# include	"SnakeCell.hpp"
# include	"AxisCell.hpp"
# include	"FoodCell.hpp"
# include	"RandomCell.hpp"
# include	"utils/Dimensions.hpp"
# include	"SnakeMenu.hpp"

namespace	arcade
{
  namespace	snake
  {
    class		GameSnake : public api::AGame
    {
      typedef std::vector<ACell> t_cell_tab;
      typedef t_cell_tab::iterator t_cell_tab_i;
      typedef t_cell_tab::const_iterator t_cell_tab_ci;

      typedef std::vector<SnakeCell> t_snakecell_tab;
      typedef t_snakecell_tab::iterator t_snakecell_tab_i;
      typedef t_snakecell_tab::const_iterator t_snakecell_tab_ci;

      typedef t_snakecell_tab::reverse_iterator t_snakecell_tab_ri;

      typedef std::vector<AxisCell> t_axiscell_tab;
      typedef t_axiscell_tab::iterator t_axiscell_tab_i;
      typedef t_axiscell_tab::const_iterator t_axiscell_tab_ci;

    private:
      t_snakecell_tab	_player;
      t_axiscell_tab	_turn_points;
      FoodCell		_food_cell;
      RandomCell	_random_cell;
      int		_score;
      bool		_game_over;
      bool		_easy_mode;
      ::arcade::utl::Dimensions	_boardDimensions;
      SnakeMenu		_menu;
      bool		_first_play;

    public:
      GameSnake();
      ~GameSnake();

      int		init(api::IGraphic *graphic) override;
      int		play(api::IEvents const &event) override;
      int		play(int c);
      int		close() override;
      int		getScore() const;
      int		restart();
      int		reloadSprites();
      void		saveScore();

      void		initPlayer();
      void		displayGameBoard();
      void		displayPlayer();
      void		updatePlayer(api::IEvents const &event);
      void		updatePlayerParts();
      void		addSnakeNode(int multiple_add = 0);
      void		checkFoodEating();
      int		checkCollisions();
      void		recalculatePosition(t_snakecell_tab_i &i);

      void		protocolUpdatePlayer(int c);

      void		protocolWhereAmI();
      void		protocolGetMap();
      void		protocolGoUp();
      void		protocolGoDown();
      void		protocolGoLeft();
      void		protocolGoRight();
      void		protocolPlay();
    };
  };
};

#endif		//CPP_ARCADE_GAMESNAKE_HPP_
