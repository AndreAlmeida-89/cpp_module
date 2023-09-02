# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 18:55:24 by andde-so          #+#    #+#              #
#    Updated: 2023/09/02 00:43:14 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= tests

OLD_LOG = 19920104_091532.log

NEW_LOG	= new_log.log

SRC		= Account.cpp tests.cpp

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
	./$(NAME) > $(NEW_LOG)
	diff --side-by-side --width=180 $(OLD_LOG) $(NEW_LOG); [ $$? -eq 1 ]
	$(RM) $(NEW_LOG)


.PHONY: all clean fclean re run
