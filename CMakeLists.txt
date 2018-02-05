cmake_minimum_required(VERSION 3.6)
project(cpp_arcade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++11")

set(SOURCES_FILES
        src/main.cpp
        include/loader/DLLoader.hpp
        include/API/IContext.hpp
        include/API/Protocol.hpp
        include/API/AGame.hpp
        include/API/IEvents.hpp
        include/loader/DLInterface.hpp
        include/loader/DLLoaderManager.hpp
        include/API/IGraphic.hpp include/exceptions/loaderExceptions.cpp
        include/exceptions/loaderExceptions.hpp
        src/Core/Core.cpp
        include/Core.hpp
        src/Core/Engine.cpp
        include/Engine.hpp
        src/Core/Framerate.cpp
        include/Framerate.hpp include/API/Exceptions.hpp)
#set(SNAKE_GAME
  #      src/snake/lib_endpoint.cpp include/snake/SnakeGame.hpp)

set(GRAPHICS include/API/IContext.hpp)
set(GAME include/API/AGame.hpp)
set(SNAKE_SRC games/snake/src/SnakeCell.cpp
        games/snake/src/GameSnake.cpp
        games/snake/include/SnakeCell.hpp
        games/snake/include/GameSnake.hpp
        games/snake/include/AxisCell.hpp
        games/snake/include/BoardCell.hpp
        games/snake/include/ACell.hpp
        games/snake/include/FoodCell.hpp)

set(NCURSE lib/ncurse/src/ContextNcurse.cpp
        lib/ncurse/src/GraphicsNcurse.cpp
        lib/ncurse/src/EventsNcurse.cpp
        lib/ncurse/src/NcurseExceptions.cpp
        lib/ncurse/include/NcurseExceptions.hpp
        lib/ncurse/include/EventsNcurse.hpp
        lib/ncurse/include/ContextNcurse.hpp
        lib/ncurse/include/GraphicsNcurse.hpp)

include_directories(./ include/API
  include
  include/snake
  games/snake/include
  games/centipede/include
  lib/ncurse/include
  lib/openGL/include
  lib/SFML/include)

set(SFML lib/SFML/src/SFMLContext.cpp
        lib/SFML/include/SFMLContext.hpp
        lib/SFML/src/SFMLGraphics.cpp
        lib/SFML/include/SFMLGraphics.hpp
        lib/SFML/src/SFMLEvents.cpp
        lib/SFML/include/SFMLEvents.hpp lib/SFML/src/endpoints.cpp)

set(OPENGL
        lib/openGL/src/OpenGLGraphic.cpp
        lib/openGL/src/OpenGLContext.cpp
        lib/openGL/src/OpenGLEvents.cpp
        lib/openGL/include/OpenGLContext.hpp
        lib/openGL/include/OpenGLGraphic.hpp
        lib/openGL/include/OpenGLEvents.hpp)

set(CENTIPEDE
        games/centipede/include/GameManager.hpp
        games/centipede/include/Grid.hpp
        games/centipede/src/Grid.cpp
        games/centipede/src/AEntity.cpp
        games/centipede/include/AEntity.hpp
        games/centipede/src/Player.cpp
        games/centipede/include/Player.hpp
        games/centipede/src/Obstacle.cpp
        games/centipede/include/Obstacle.hpp
        games/centipede/include/IDrawableEntity.hpp games/centipede/src/endpoints.cpp games/centipede/include/EntityFactory.hpp games/centipede/src/Centipede.cpp games/centipede/include/Centipede.hpp games/centipede/src/GameManager.cpp games/centipede/include/MouliInterface.cpp games/centipede/include/MouliInterface.hpp)

add_library(arcade_centipede SHARED ${CENTIPEDE})
#add_library(game SHARED ${SNAKE_GAME} API/AGame.hpp)

#add_library(testgame SHARED ${GAME})
#add_library(testgraphic SHARED ${GRAPHICS})

add_library(arcade_ncurse SHARED ${NCURSE})
add_library(arcade_snake SHARED ${SNAKE_SRC})
add_library(arcade_sfml SHARED ${SFML})
add_library(arcade_opengl SHARED ${OPENGL})

TARGET_LINK_LIBRARIES(arcade_sfml libsfml-window.so libsfml-system.so libsfml-graphics.so)
add_executable(arcade ${SOURCES_FILES})
TARGET_LINK_LIBRARIES(arcade libdl.so)
#add_library(libcore SHARED ${GRAPHICS})