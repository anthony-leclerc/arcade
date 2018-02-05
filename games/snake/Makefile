##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Mar  6 15:29:32 2017 Anthony LECLERC
## Last update Sun Apr  9 04:14:44 2017 Sylvain Chaugny
##

CXX		=	g++

CXXFLAGS	+=	-W -Wall -Wextra -std=c++14

DEBUG		?=	0

ifeq ($(DEBUG), 1)
CXXFLAGS	+=	-g -ggdb3
endif

NAME		=	lib_arcade_snake.so
NAME		?=	$(SNAKE_LIB)

RM		=	rm -f

CXXFLAGS	+=	-I./include -I../../include

include			sources.mk

OBJ		=	$(SRC:.cpp=.o)

all:			$(NAME)

bonus:			fclean
			make re -C bonus/
			mv bonus/$(SNAKE_LIB) .

$(NAME):		$(OBJ)
			$(CXX) $(CXXFLAGS) -shared -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)
			$(RM) $(OBJ_BONUS)

fclean:			clean
			make fclean -C bonus/
			$(RM) $(NAME)

re:			fclean all

.cpp.o:
			$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
