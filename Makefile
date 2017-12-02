NAME = fdf
SRC = src/main.c		\
	  src/file_reader.c	\
	  src/new_plotter.c	\
	  src/line_draw.c	\
	  src/rainbow.c		\

BIN = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit

all:
	make -C ./libft
	gcc -o $(NAME) $(SRC) -L./libft -lft -L./minilibx -lmlx $(FLAGS) -g
