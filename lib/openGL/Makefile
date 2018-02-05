## Makefile for makefile in /home/baldas/Prog/base_project
##
## Made by Hugo Baldassin
## Login   <baldas_h@epitech.net>
##
## Started on  Tue Mar 15 17:53:08 2016 Hugo Baldassin
## Last update Fri Apr  7 17:06:04 2017 Anthony LECLERC
##

NAME	=	lib_arcade_openGL.so

SRC	=	src/OpenGLContext.cpp	\
		src/OpenGLGraphic.cpp	\
		src/OpenGLEvents.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS +=	-W -Wall -Wextra -std=c++11

IPATHS	=	-I../../include/API/ -I./include/ -I../../include/

LFLAGS	=	-L./lib -lsfml-graphics -lsfml-window -lsfml-system -lglut -lGLU -lGL

ifeq ($(DEBUG), 1)
CFLAGS	+=	-g -ggdb3
endif

#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${PWD}/lib_glut/

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ -shared -o $(NAME) $(OBJ) $(LFLAGS)
clean	:
		rm -rf $(OBJ)
fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

.cpp.o:
		g++ $(CXXFLAGS) $(IPATHS) $(LFLAGS) -fPIC -c $< -o $@
