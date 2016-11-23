# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by rdieulan          #+#    #+#              #
#    Updated: 2016/11/23 03:26:29 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

LIBFT = libft/libft.a
LIBVEC = libvec/lib_vec.a
GLIB = minilibx_macos/libmlx.a

SRC = main.c \
	  effect.c \
	  draw.c \
	  color.c \
	  get_config.c \
	  init_obj.c \
	  key_event.c \
	  parse_obj.c \
	  parse_cam.c \
	  red_cross.c \
	  cast_ray.c \
	  cone.c \
	  cylinder.c \
	  plane.c \
	  sphere.c

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

GFLAG = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	make -C minilibx_macos
	make -C libvec
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(GFLAG) $(SRCO) $(LIBFT) $(LIBVEC) $(GLIB)

clean:
	make -C libft clean
	make -C minilibx_macos clean
	make -C libvec clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	make -C libvec fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
