# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:34:16 by nzhuzhle          #+#    #+#              #
#    Updated: 2023/09/06 17:34:23 by nzhuzhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I ./

SRC = pipex.c aux.c
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
SRC_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft

%.o: %.c Makefile
	$(CC) $(FLAGS) -c $< -o $@

all: make_lib $(NAME)

make_lib: 
	$(MAKE_LIBFT)

-include $(DEPS)
$(NAME): $(OBJ) $(SRC_LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEPS)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
