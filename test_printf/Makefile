# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 14:22:25 by rdieulan          #+#    #+#              #
#    Updated: 2016/02/15 14:36:23 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf
PATH_PRINTF = ../printf/
PATH_LIBFT = ../printf/libft/
FLAG = -Werror -Wall -Wextra
SRC = main.c \
	$(PATH_PRINTF)ft_printf.c \
	$(PATH_LIBFT)libft.a

all : $(NAME)

$(NAME) :
	gcc $(FLAG) $(SRC) -o $(NAME)

clean :
	/bin/rm $(NAME)

re : clean all
