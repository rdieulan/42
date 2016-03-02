# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 16:41:18 by jnaddef           #+#    #+#              #
#    Updated: 2016/03/02 18:43:37 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = ./srcs/
SRCS = $(SRC_PATH)main.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = ./libft/
LIB_DIR = libft/

.PHONY: $(LIBS) all clean fclean re

all: $(LIBS) $(NAME)

$(LIBS):
	$(MAKE) -C $@

$(NAME):  
	$(CC) $(CFLAGS) $(SRCS) -L./$(LIB_DIR) -lft -I$(LIB_DIR) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
