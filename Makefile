##
## EPITECH PROJECT, 2023
## NonoLePetitRobot [WSL: Ubuntu]
## File description:
## Makefile
##

SRC			=	src/AComponent.cpp			\
				src/ElementaryComponent.cpp	\
				src/main.cpp				\
				src/Pin.cpp					\
				src/SpecialComponent.cpp	\
				src/Circuit.cpp				\
				src/ComponentFactory.cpp	\
				src/Link.cpp				\
				src/Parser.cpp				\
				src/Component4030.cpp		\
				src/Component4069.cpp		\
				src/Component4071.cpp		\
				src/Component4081.cpp		\
				src/Component4001.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

GCC			=	g++

CPPFLAGS	=	 -std=c++20 -I./include -Wall -Wextra -Werror

DEBUG_FLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:	CXXFLAGS += $(DEBUG_FLAGS)
debug:	re

.PHONY:	all clean fclean re debug
