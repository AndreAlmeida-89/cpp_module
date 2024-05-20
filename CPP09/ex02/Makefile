# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 11:54:15 by andde-so          #+#    #+#              #
#    Updated: 2024/05/20 12:54:26 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe

SRC		=	main.cpp


OBJ		= $(SRC:%.cpp=%.o)

CFLAGS	= -Wall -Wextra -Werror

STD		= -std=c++98

CC		= c++

RM		= rm -f

%.o:	%.cpp
	$(CC) -I. $(CFLAGS) $(STD) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -I. $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

run: re
	./$(NAME) 3 5 9 7 4
	./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`


.PHONY: all clean fclean re run test
