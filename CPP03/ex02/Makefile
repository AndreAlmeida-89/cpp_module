# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 11:54:15 by andde-so          #+#    #+#              #
#    Updated: 2024/01/05 23:12:26 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= repetitive_work

SRC		=	ClapTrap.cpp	\
			ScavTrap.cpp	\
			FragTrap.cpp	\
			main.cpp		\

OBJ		= $(SRC:%.cpp=%.o)

CFLAGS	= -Wall -Wextra -Werror

STD		= -std=c++98

CC		= g++

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
