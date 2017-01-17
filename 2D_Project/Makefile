# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/24 13:16:13 by rdieulan          #+#    #+#              #
#    Updated: 2017/01/02 15:33:24 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gamebin

LIBFT = libft/libft.a

SRC = main.c 

SRCO = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(SRCO) $(LIBFT)

clean:
	make -C libft clean
	rm -f $(SRCO)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
