NAME = fractol
SRC = main.c\
	  mandelbrot.c\
	  julia.c\
	  draw.c

OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wextra -Werror -Wall -L/usr/local/lib/ -I/usr/local/include -lmlx\
	-framework OpenGL -framework AppKit
RM = /bin/rm -f
LIBFT = ./libft/libft.a
I = -I ./libft/
L = -L ./libft/ -lft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo "make: executable's compilation"
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(L)

$(OBJ):
	@echo "make: object's compilation"
	@gcc -c $(SRC) $(I)

$(LIBFT):
	@make -C ./libft/
	@make clean -C ./libft/

clean:
	@echo "make: object's deletion"
	@$(RM) $(OBJ)

fclean: clean
	@echo "make: executable's deletion"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
