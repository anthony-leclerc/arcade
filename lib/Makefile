##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Mar  6 15:29:32 2017 Anthony LECLERC
## Last update Sun Apr  9 17:40:53 2017 Sylvain Chaugny
##

NCURSE_DIR		=	ncurse
export NCURSE_LIB	=	lib_arcade_ncurse.so
SFML_DIR        	=   	SFML
export SFML_LIB        	=   	lib_arcade_sfml.so
OPENGL_DIR		=	openGL
export OPENGL_LIB       =   	lib_arcade_openGL.so

all:			  ncurse_all sfml_all openGL_all

## NCURSE

ncurse_all:
			make -C $(NCURSE_DIR)
			cp $(NCURSE_DIR)/$(NCURSE_LIB) .

.PHONY: ncurse_all

ncurse_clean:
			make clean -C $(NCURSE_DIR)

ncurse_fclean:
			make fclean -C $(NCURSE_DIR)
			rm -f $(NCURSE_LIB)

ncurse_re:		ncurse_fclean ncurse_all

## OPENGL

openGL_all:
			make -C $(OPENGL_DIR)
			cp $(OPENGL_DIR)/$(OPENGL_LIB) .

.PHONY:			openGL_all

openGL_clean:
			make clean -C $(OPENGL_DIR)

openGL_fclean:
			make fclean -C $(OPENGL_DIR)
			rm -f $(OPENGL_LIB)

openGL_re:		openGL_fclean openGL_all

## SFML

sfml_all:
			make -C $(SFML_DIR)
			cp $(SFML_DIR)/$(SFML_LIB) .

.PHONY:			sfml_all

sfml_clean:
			make clean -C $(SFML_DIR)

sfml_fclean:
			make fclean -C $(SFML_DIR)
			rm -f $(SFML_LIB)

sfml_re:		sfml_fclean sfml_all

## GLOBAL

re:			openGL_re ncurse_re sfml_re openGL_re

clean:			ncurse_clean sfml_clean openGL_clean

fclean:			ncurse_fclean sfml_fclean openGL_fclean
