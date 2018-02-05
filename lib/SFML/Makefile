##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Mar  6 15:29:32 2017 Anthony LECLERC
## Last update Sun Apr  9 03:20:03 2017 Hugo Baldassin
##

NAME =		lib_arcade_sfml.so

CXX =		g++ -std=c++11

CXXFLAGS =	-W -Wall -Wextra

INC =		-I./include/ -I../../include

LDXXFLAGS = 	-L./lib \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \

include		sources.mk

OBJ =		$(SRC:.cpp=.o)

#export LD_LIBRARY_PATH:=${LD_LIBRARY_PATH}:${PWD}/SFML

all: 		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) -shared $(OBJ) $(CXXFLAGS) $(LDXXFLAGS) $(INC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o:	%.cpp
	$(CXX) -o $@ -c $< -fPIC $(CXXFLAGS) $(LDXXPRELOAD) $(LDXXFLAGS) $(INC)
