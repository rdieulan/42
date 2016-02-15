# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/16 14:02:58 by rdieulan          #+#    #+#              #
#    Updated: 2016/01/29 16:27:41 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
PATH_SRC = ./srcs/
HEADER = ./includes/
FLAG = -Werror -Wall -Wextra
OPTION = -c -I $(HEADER)

SRC = $(PATH_SRC)main.c

OBJ = main.o

all : $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(OPTION) $(SRC)
	gcc $(FLAG) -I $(HEADER) $(OBJ) -o $(NAME)

clean:
	make clean -C libft
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
