# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 18:55:24 by andde-so          #+#    #+#              #
#    Updated: 2023/08/30 23:27:14 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

INC_DIR	= include

SRC_DIR = src

OBJ_DIR = obj

SRC		= $(wildcard $(SRC_DIR)/*.cpp)

OBJ		= $(SRC:%.cpp=%.o)

CFLAGS	= -I$(INC_DIR) -Wall -Wextra -Werror

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
