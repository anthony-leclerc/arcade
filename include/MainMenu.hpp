//
// MainMenu.hpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/src/Core
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Sun Apr  9 07:31:43 2017 Sylvain Chaugny
// Last update Sun Apr  9 09:33:34 2017 Sylvain Chaugny
//

#ifndef		CPP_ARCADE_MAINMENU_HPP_
# define	CPP_ARCADE_MAINMENU_HPP_

# include	<vector>
# include	"API/IGraphic.hpp"
# include	"API/IEvents.hpp"
# include	"Framerate.hpp"

namespace	arcade
{
  class		MainMenu
  {
  public:
    typedef std::vector<std::string> t_libs_tab;
    typedef std::vector<std::string> t_games_tab;
    typedef std::vector<std::string>::iterator t_tab_i;

  private:
    t_libs_tab _libs_tab;
    t_games_tab _games_tab;
    api::IGraphic *_graphic;
    std::string _current_graphic;
    std::string _current_game;

  public:
    MainMenu();
    ~MainMenu();

    void	setGraphicModule(arcade::api::IGraphic *graphic);
    int		displayMainMenu(api::IEvents const &event);
    std::string	parseName(std::string const &name);
    void	addLibName(std::string const &name);
    void	addGameName(std::string const &name);
    void	setCurrentGraphic(std::string const &name);
    void	setCurrentGame(std::string const &name);
  };
};

#endif		//CPP_ARCADE_MAINMENU_HPP_
