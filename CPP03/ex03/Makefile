# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 11:54:15 by andde-so          #+#    #+#              #
#    Updated: 2023/11/29 08:27:23 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= now_its_weird

SRC		=	ClapTrap.cpp	\
			ScavTrap.cpp	\
			FragTrap.cpp	\
			DiamondTrap.cpp	\
			main.cpp		\

OBJ		= $(SRC:%.cpp=%.o)

CFLAGS	= -Wall -Wextra -Werror -Wno-shadow

STD		= -std=c++98

CC		= c++

RM		= rm -f

%.o:	%.cpp
	$(CC) $(CFLAGS) $(STD) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re run
