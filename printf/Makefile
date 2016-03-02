# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/07 07:57:11 by rdieulan          #+#    #+#              #
#    Updated: 2016/03/02 14:02:49 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinf.a

SRC = ft_printf.c\

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft
	clang -o $(NAME) $(FLAG) $(SRC)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
