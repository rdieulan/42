# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/22 17:06:10 by jealonso          #+#    #+#              #
#    Updated: 2015/03/06 12:02:36 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTPATH	=	libft

LIBFT	=	$(LFTPATH)/libft.a

INCLPATH =	includes

OBJSPATH =	objs

SRCSPATH =	srcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCLPATH) -I $(LFTPATH)/$(INCLPATH)

LDFLAGS	= -L $(LFTPATH) -lft

NAME = fillit

SRCS = \
		ft_get_tetriminos.c \
		ft_get_coord.c \
		ft_search_range.c \
		ft_check_validity.c \

OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HFILES = fillit.h

HEAD = $(patsubst %.h, includes/%.h, $(HFLIES))

all: $(OBJSPATH) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJSPATH)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	rm -f $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	mkdir $@

$(LIBFT):
	$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "Pouet"
