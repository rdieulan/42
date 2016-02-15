# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/07 07:57:11 by rdieulan          #+#    #+#              #
#    Updated: 2016/02/07 07:57:22 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRC = ft_printf.c\
		main.c

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -o $(NAME) $(FLAG) $(SRC)

clean:
	rm -rf *.o
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
