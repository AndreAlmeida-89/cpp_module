# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 11:54:15 by andde-so          #+#    #+#              #
#    Updated: 2023/09/23 00:30:16 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= serena_my_love

SRC		=	main.cpp		\
			ClapTrap.cpp	\
			ScavTrap.cpp	\

OBJ		= $(SRC:%.cpp=%.o)

CFLAGS	= -Wall -Wextra -Werror

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
