# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by rdieulan          #+#    #+#              #
#    Updated: 2017/01/17 15:58:27 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIB = libft/libft.a

GLIB = minilibx_macos/libmlx.a

SRC = main.c \
	  color_wall.c \
	  key_event.c \
	  draw.c \
	  color.c \
	  game.c \
	  motion_notify.c \
	  red_cross.c \
	  integrity.c \
	  error.c \
	  loader.c

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

GFLAG = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(GFLAG) $(SRCO) $(LIB) $(GLIB) -fsanitize=address

clean:
	make -C libft clean
	make -C minilibx_macos clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
