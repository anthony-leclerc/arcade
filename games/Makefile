##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Mar  6 15:29:32 2017 Anthony LECLERC
## Last update Sun Apr  9 11:16:18 2017 Anthony LECLERC
##

export SNAKE_LIB =	lib_arcade_snake.so
export CENTIPEDE_LIB =	lib_arcade_centipede.so

GAMES=	snake \
	centipede

all:		$(GAMES)

games:		 $(GAMES)

$(GAMES):
	@$(MAKE) -C $@ && \
	cp $@/$$(ls $@ | grep -e "^lib_arcade_$@.so$$") .

bonus:
			make bonus -C snake
			mv snake/$(SNAKE_LIB) .

.PHONY:			$(GAMES) games bonus

re:			fclean all

clean:
			@for game in $(GAMES); do \
				$(MAKE) $@ -C $$game; \
			done

_fclean:
			rm -rf $(SNAKE_LIB)
			rm -rf $(CENTIPEDE_LIB)

fclean:			_fclean
			@for game in $(GAMES); do \
				$(MAKE) $@ -C $$game; \
			done
