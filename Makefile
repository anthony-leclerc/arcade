##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Last update Sun Apr  9 15:43:52 2017 Sylvain Chaugny
## Last update Thu Apr  6 00:41:36 2017 Sylvain Chaugny
##

CXX		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -std=c++14

DEBUG		?=	0

ifeq ($(DEBUG), 1)
CXXFLAGS	+=	-g -ggdb3
endif

NAME		=	arcade

# Path to graphics lib directory
GRAPHIC		=	./lib

# Path to games lib directory
GAME		=	./games

RM		=	rm -f

CXXFLAGS	+=	-I./include

include			sources.mk

OBJ		=	$(SRC:.cpp=.o)

LD_FLAGS	=	-ldl

all:			games $(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(CXXFLAGS) $(LD_FLAGS) -o $(NAME) $(OBJ)

doc:			doc_clean
			doxygen api-doc.cfg

doc_clean:
			rm -rf doc/

## GAMES

games:
			make -C $(GAME)

games_re:
			make re -C $(GAME)

games_fclean:
			make fclean -C $(GAME)

games_clean:
			make clean -C $(GAME)

games_bonus:
			make bonus -C $(GAME)

## LIBS

libs:
			make -C $(GRAPHIC)

libs_clean:
			make clean -C $(GRAPHIC)

libs_fclean:
			make fclean -C $(GRAPHIC)

libs_re:
			make re -C $(GRAPHIC)

.PHONY: games

_clean:
			$(RM) $(OBJ)

clean:			_clean
			make clean -C $(GAME)

_fclean:		_clean
			$(RM) $(NAME)

fclean:			_fclean
			make fclean -C $(GAME)

re:			fclean all

.cpp.o:
			$(CXX) $(CXXFLAGS) $(LD_FLAGS) -c $< -o $@
