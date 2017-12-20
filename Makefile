NAME = fdf
SRC = src/main.c		\
	  src/file_reader.c	\
	  src/new_plotter.c	\
	  src/line_draw.c	\
	  src/rainbow.c		\

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit

all:
	make -C ./libft
	gcc -o $(NAME) $(SRC) -L./libft -lft -L./minilibx -lmlx $(FLAGS) -g

clean:
	make -C ./libft/ clean

fclean:
	make -C ./libft/ fclean
	@rm -f $(NAME)

re: fclean all
