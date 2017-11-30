NAME = testread
FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit
FILES = fr_tmain.c file_reader.c new_plotter.c rainbow.c 
molly:
	make -C ./libft
	gcc -o $(NAME) $(FILES) -L./libft -lft -L./minilibx -lmlx $(FLAGS) -g
