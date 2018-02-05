/*
** GameSnake.cpp for arcade in /home/sylvain/Documents/projets/tek2/c++/cpp_arcade/games/snake
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Mar 19 23:05:29 2017 Sylvain Chaugny
** Last update Sun Apr  9 15:41:07 2017 Sylvain Chaugny
*/

#include	<fstream>
#include	<ios>
#include	"API/IEvents.hpp"
#include	"API/IGraphic.hpp"
#include	"GameSnake.hpp"
#include	"SnakeCell.hpp"
#include	"AxisCell.hpp"
#include	"utils/Color.hpp"
#include	"API/Protocol.hpp"
#include	"SnakeException.hpp"
#include	"utils/Date.hpp"

arcade::snake::GameSnake::GameSnake()
{
  setName("Snake");
  _turn_points.clear();
  _score = 0;
  _game_over = false;
  _easy_mode = false;
  _first_play = true;
}

arcade::snake::GameSnake::~GameSnake()
{
}

int		arcade::snake::GameSnake::reloadSprites()
{
  arcade::utl::Position pos;
  arcade::utl::Dimensions dim;
  int		id;
  t_snakecell_tab_i i;

  _boardDimensions.width = (graphic->getDimensions().width - graphic->getDimensions().width / 3);
  _boardDimensions.height = (graphic->getDimensions().height);
  _menu.setGraphic(graphic);
  _food_cell.setRandomCoordinates(_boardDimensions);
  for (i = _player.begin(); i != _player.end(); i++)
    {
      if (i->getIsHead())
	id = graphic->loadSprite(arcade::TextureID::PLAYER_HEAD, "ressource/player_head.png", pos, dim);
      else
	id = graphic->loadSprite(arcade::TextureID::PLAYER_BODY, "ressource/player_body.png", pos, dim);

      recalculatePosition(i);

      if (id == -1)
	throw arcade::snake::SnakeException("reloadSprites: Unable to load texture");
      i->setSpriteID(id);
    }
  recalculatePosition(i);
  _turn_points.clear();
  return (0);
}

void		arcade::snake::GameSnake::recalculatePosition(t_snakecell_tab_i &i)
{
  static int	add = -1 * (_player.size() / 2);

  if (i == _player.end())
    {
      add = -1 * (_player.size() / 2);
      return ;
    }
  i->setPosX(_boardDimensions.width / 2 + add);
  i->setPosY(_boardDimensions.height / 2);
  i->setDirection(arcade::api::IEvents::Key::RIGHT);
  add++;
}

int		arcade::snake::GameSnake::play(arcade::api::IEvents const &event)
{
  int		res;

  if (_first_play)
    {
      res = _menu.displayMenu(event);
      if (res)
	_first_play = false;
      _easy_mode = (res == 2) ? true : false;
    }
  else if (_game_over)
    {
      res = _menu.displayGameOver(event, _score);
      if (res)
	restart();
      _easy_mode = (res == 2) ? true : false;
    }
  else
    {
      displayGameBoard();
      displayPlayer();
      updatePlayer(event);
    }
  return 0;
}

int		arcade::snake::GameSnake::close()
{
  _player.clear();
  _turn_points.clear();
  _score = 0;
  return 0;
}

int		arcade::snake::GameSnake::getScore() const
{
  return _score;
}

int		arcade::snake::GameSnake::restart()
{
  _food_cell.setRandomCoordinates(_boardDimensions);
  _game_over = false;
  _player.clear();
  _turn_points.clear();
  _score = 0;
  initPlayer();
  return 0;
}

int		arcade::snake::GameSnake::init(arcade::api::IGraphic *graphics)
{
  if (graphics != NULL)
    {
      setGraphicModule(graphics);
      _boardDimensions.width = (graphic->getDimensions().width - graphic->getDimensions().width / 3);
      _boardDimensions.height = (graphic->getDimensions().height);
      _menu.setGraphic(graphics);
    }
  else
    {
      _boardDimensions.width = 20;
      _boardDimensions.height = 20;
    }
  srand(time(NULL));
  _food_cell.setRandomCoordinates(_boardDimensions);
  initPlayer();
  return 0;
}

/*
** SNAKE METHODS
*/

void		arcade::snake::GameSnake::saveScore()
{
  std::ofstream	file("ressource/snake_scores.txt", std::ios_base::app | std::ios_base::out);
  std::string	score;
  arcade::utl::Date	date;

  if (!file.good())
    throw SnakeException("The score file could not be opened");
  score = date.getFormattedData() + std::to_string(_score);
  file << score << std::endl;
}

void		arcade::snake::GameSnake::addSnakeNode()
{
  SnakeCell	last;
  SnakeCell	cell;
  arcade::utl::Position pos;
  arcade::utl::Dimensions dim;

  last = _player.front();
  cell.setPos(last.getPos());
  cell.setDirection(last.getDirection());
  cell.setIsNew(true);
  cell.setSpriteID(graphic->loadSprite(arcade::TextureID::PLAYER_BODY, "ressource/player_body.png", pos, dim));
  if (cell.getSpriteID() == -1)
    throw arcade::snake::SnakeException("addSnakeNode: Unable to load texture");
  _player.insert(_player.begin(), cell);
}

void		arcade::snake::GameSnake::displayGameBoard()
{
  size_t	x;
  size_t	y;
  int		id;

  y = 0;
  while (y < _boardDimensions.height)
    {
      x = 0;
      while (x < _boardDimensions.width)
	{
	  if (x == 0 || x + 1 == _boardDimensions.width || y == 0 || y + 1 == _boardDimensions.height)
	    {
	      id = graphic->loadSprite(arcade::TextureID::WALL, "ressource/wall.png", arcade::utl::Position(0, 0), arcade::utl::Dimensions(0, 0));
	      if (id == -1)
		throw arcade::snake::SnakeException("displayGameBoard: Unable to load texture");
	      graphic->drawSprite(arcade::utl::Position(x, y), id, arcade::utl::Color(255, 255, 255));
	    }
	  x++;
	};
      y++;
    }
}

void		arcade::snake::GameSnake::displayPlayer()
{
  t_snakecell_tab_ci	i;
  arcade::utl::Position pos;
  arcade::utl::Dimensions dim;
  int		powerup_id;

  for (i = _player.begin(); i != _player.end(); i++)
    graphic->drawSprite(i->getPos(), i->getSpriteID(), arcade::utl::Color(255, 0, 0));

  powerup_id = graphic->loadSprite(arcade::TextureID::POWERUP, "ressource/powerup.png", pos, dim);
  if (powerup_id == -1)
    throw arcade::snake::SnakeException("displayPlayer: Unable to load texture");

  graphic->drawSprite(_food_cell.getPos(), powerup_id, arcade::utl::Color(0, 255, 0));
}

void		arcade::snake::GameSnake::updatePlayer(arcade::api::IEvents const &event)
{
  arcade::api::IEvents::Key	backup;
  AxisCell	axis;

  backup = _player.back().getDirection();
  if (event.keyPressed(arcade::api::IEvents::Key::UP) && backup != arcade::api::IEvents::Key::UP && backup != arcade::api::IEvents::Key::DOWN)
    _player.back().setDirection(arcade::api::IEvents::Key::UP);
  if (event.keyPressed(arcade::api::IEvents::Key::DOWN) && backup != arcade::api::IEvents::Key::DOWN && backup != arcade::api::IEvents::Key::UP)
    _player.back().setDirection(arcade::api::IEvents::Key::DOWN);
  if (event.keyPressed(arcade::api::IEvents::Key::LEFT) && backup != arcade::api::IEvents::Key::LEFT && backup != arcade::api::IEvents::Key::RIGHT)
    _player.back().setDirection(arcade::api::IEvents::Key::LEFT);
  if (event.keyPressed(arcade::api::IEvents::Key::RIGHT) && backup != arcade::api::IEvents::Key::RIGHT && backup != arcade::api::IEvents::Key::LEFT)
    _player.back().setDirection(arcade::api::IEvents::Key::RIGHT);
  if (backup != _player.back().getDirection())
    {
      axis.setPos(_player.back().getPos());
      axis.setDirection(_player.back().getDirection());
      _turn_points.push_back(axis);
    }
  updatePlayerParts();
}

void		arcade::snake::GameSnake::updatePlayerParts()
{
  t_axiscell_tab_i	axis_erase;
  bool		erase;

  erase = false;
  for (t_snakecell_tab_i i = _player.begin(); i != _player.end(); i++)
    {
      if (!i->getIsHead())
	{
	  for (t_axiscell_tab_i j = _turn_points.begin(); j != _turn_points.end(); j++)
	    {
	      if (j->getPosX() == i->getPosX() && j->getPosY() == i->getPosY())
		{
		  if (i == _player.begin())
		    {
		      erase = true;
		      axis_erase = j;
		    }
		  i->setDirection(j->getDirection());
		}
	    }
	}
      if (!i->getIsNew())
	i->updatePosition();
      else
	i->setIsNew(false);
    }
  checkFoodEating();
  if (erase)
    _turn_points.erase(axis_erase);
  if (checkCollisions())
    return ;
}

int		arcade::snake::GameSnake::checkCollisions()
{
  SnakeCell	head;

  head = _player.back();
  if (!_easy_mode)
    {
      if (head.getPosX() == 0 || head.getPosX() + 1 == _boardDimensions.width ||
	  head.getPosY() == 0 || head.getPosY() + 1 == _boardDimensions.height)
	{
	  _game_over = true;
	  saveScore();
	  return 1;
	}
    }
  for (t_snakecell_tab_i i = _player.begin(); i != _player.end(); i++)
    {
      if (_easy_mode)
	{
	  if (i->getPosX() == 0)
	    i->setPosX(_boardDimensions.width - 2);
	  if (i->getPosX() == _boardDimensions.width - 1)
	    i->setPosX(1);
	  if (i->getPosY() == 0)
	    i->setPosY(_boardDimensions.height - 2);
	  if (i->getPosY() == _boardDimensions.height - 1)
	    i->setPosY(1);
	}
      if (!i->getIsHead() && i->getPosX() == head.getPosX() && i->getPosY() == head.getPosY())
	{
	  _game_over = true;
	  saveScore();
	  return 1;
	}
    }
  return 0;
}

void		arcade::snake::GameSnake::checkFoodEating()
{
  if (_player.back().getPosX() == _food_cell.getPosX() &&
      _player.back().getPosY() == _food_cell.getPosY())
    {
      _score += 10;
      addSnakeNode();
      _food_cell.setRandomCoordinates(_boardDimensions);
    }
}

void		arcade::snake::GameSnake::initPlayer()
{
  SnakeCell	cell;
  arcade::utl::Position pos;
  arcade::utl::Dimensions dim;
  int		current_id;

  cell.setPosY(_boardDimensions.height / 2);
  cell.setPosX(_boardDimensions.width / 2 - 2);

  if (graphic)
    {
      current_id = graphic->loadSprite(arcade::TextureID::PLAYER_BODY, "ressource/player_body.png", pos, dim);
      if (current_id == -1)
	throw arcade::snake::SnakeException("initPlayer: Unable to load texture");
    }
  else
    current_id = 0;
  cell.setSpriteID(current_id);
  _player.push_back(cell);
  cell.setPosX(_boardDimensions.width / 2 - 1);
  cell.setSpriteID(current_id);
  _player.push_back(cell);
  cell.setPosX(_boardDimensions.width / 2);
  cell.setSpriteID(current_id);
  _player.push_back(cell);
  cell.setPosX(_boardDimensions.width / 2 + 1);
  cell.setIsHead(true);

  if (graphic)
    {
      current_id = graphic->loadSprite(arcade::TextureID::PLAYER_HEAD, "ressource/player_head.png", pos, dim);
      if (current_id == -1)
	throw arcade::snake::SnakeException("initPlayer: Unable to load texture");
      cell.setSpriteID(current_id);
    }
  _player.push_back(cell);
}


/*
** ANCHOR POINTS
*/


extern "C"	arcade::api::AGame *entry_point()
{
  return new arcade::snake::GameSnake;
}

extern "C"	void delete_point(arcade::api::AGame *module)
{
  delete module;
}


/*
** PROTOCOL
*/


extern "C"	void Play(void)
{
  uint16_t	tmp;

  arcade::snake::GameSnake	snake;
  snake.init(NULL);

  tmp = 0;
  while (std::cin.read(reinterpret_cast<char *>(&tmp), sizeof(uint16_t)))
    {
      snake.play(static_cast<int>(tmp));
    }
}

int		arcade::snake::GameSnake::play(int c)
{
  switch (c)
    {
    case (static_cast<int>(arcade::CommandType::WHERE_AM_I)):
      protocolWhereAmI();
      break;
    case (static_cast<int>(arcade::CommandType::GET_MAP)):
      protocolGetMap();
      break;
    case (static_cast<int>(arcade::CommandType::GO_UP)):
      protocolGoUp();
      break;
    case (static_cast<int>(arcade::CommandType::GO_DOWN)):
      protocolGoDown();
      break;
    case (static_cast<int>(arcade::CommandType::GO_LEFT)):
      protocolGoLeft();
      break;
    case (static_cast<int>(arcade::CommandType::GO_RIGHT)):
      protocolGoRight();
      break;
    case (static_cast<int>(arcade::CommandType::GO_FORWARD)):
      protocolGoUp();
      break;
    case (static_cast<int>(arcade::CommandType::SHOOT)):
      break;
    case (static_cast<int>(arcade::CommandType::ILLEGAL)):
      break;
    case (static_cast<int>(arcade::CommandType::PLAY)):
      protocolPlay();
      break;
    default:
      break;
    }
  return (0);
}

void		arcade::snake::GameSnake::protocolWhereAmI()
{
  WhereAmI	*data;
  int		i;
  int		size;

  size = _player.size() * sizeof(arcade::Position);
  data = new arcade::WhereAmI[size];
  i = 0;
  data->type = arcade::CommandType::WHERE_AM_I;
  data->lenght = _player.size();
  for (t_snakecell_tab_ri j = _player.rbegin(); j != _player.rend(); j++)
    {
      data->position[i].x = static_cast<uint16_t>(j->getPosX());
      data->position[i].y = static_cast<uint16_t>(j->getPosY());
      i++;
    }
  std::cout.write(reinterpret_cast<char *>(data), sizeof(arcade::WhereAmI) + size);
}

void		arcade::snake::GameSnake::protocolGetMap()
{
  GetMap	*data;
  size_t	x;
  size_t	y;
  int		size;

  size = _boardDimensions.height * _boardDimensions.width * sizeof(arcade::TileType);
  data = new arcade::GetMap[size];
   y = 0;
  data->type = arcade::CommandType::GET_MAP;
  data->width = _boardDimensions.width;
  data->height = _boardDimensions.height;
  while (y < _boardDimensions.height)
    {
      x = 0;
      while (x < _boardDimensions.width)
	{
	  if (x == _food_cell.getPosX() && y == _food_cell.getPosY())
	    data->tile[_boardDimensions.width * y + x] = arcade::TileType::POWERUP;
	  else
	    data->tile[_boardDimensions.width * y + x] = arcade::TileType::EMPTY;
	  x++;
	}
      y++;
    }
  std::cout.write(reinterpret_cast<char *>(data), sizeof(arcade::GetMap) + size);
}

void		arcade::snake::GameSnake::protocolGoUp()
{
  protocolUpdatePlayer(arcade::api::IEvents::Key::UP);
}

void		arcade::snake::GameSnake::protocolPlay()
{
  updatePlayerParts();
}

void		arcade::snake::GameSnake::protocolGoDown()
{
  protocolUpdatePlayer(arcade::api::IEvents::Key::DOWN);
}

void		arcade::snake::GameSnake::protocolGoLeft()
{
  protocolUpdatePlayer(arcade::api::IEvents::Key::LEFT);
}

void		arcade::snake::GameSnake::protocolGoRight()
{
  protocolUpdatePlayer(arcade::api::IEvents::Key::RIGHT);
}

void		arcade::snake::GameSnake::protocolUpdatePlayer(int c)
{
  arcade::api::IEvents::Key	backup;
  AxisCell	axis;

  backup = _player.back().getDirection();
  if (c == arcade::api::IEvents::Key::UP && backup != arcade::api::IEvents::Key::UP)
    _player.back().setDirection(arcade::api::IEvents::Key::UP);
  if (c == arcade::api::IEvents::Key::DOWN && backup != arcade::api::IEvents::Key::DOWN)
    _player.back().setDirection(arcade::api::IEvents::Key::DOWN);
  if (c == arcade::api::IEvents::Key::LEFT && backup != arcade::api::IEvents::Key::LEFT)
    _player.back().setDirection(arcade::api::IEvents::Key::LEFT);
  if (c == arcade::api::IEvents::Key::RIGHT && backup != arcade::api::IEvents::Key::RIGHT)
    _player.back().setDirection(arcade::api::IEvents::Key::RIGHT);
  if (backup != _player.back().getDirection())
    {
      axis.setPos(_player.back().getPos());
      axis.setDirection(_player.back().getDirection());
      _turn_points.push_back(axis);
    }
}
