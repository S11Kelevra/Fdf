/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:17:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/16 15:27:55 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include "./minilibx/mlx.h"

# define WHITE	0x00FFFFFF
# define GREEN	0x0000FF00
# define RED	0x00FF0000
# define BLUE	0x000000FF
# define ONE	0x00000001
# define WHAT	0xFFFFFFFF
int g_H;
int g_W;
int g_zMax;

typedef struct      s_rows
{
    char            **split_line;
    struct s_rows   *next;
    int             *array;
    int             elem;
}					t_rows;

typedef struct		s_vect
{
	int				x1;
	int				x2;
	int 			y1;
	int 			y2;
	int				z1;
	int				z2;
	int				delta_x;
	int				delta_y;
}					t_vect;

typedef struct		s_vert
{
	int 			x;
	int				y;
	int				z;
	struct s_vert	*next_x;
	struct s_vert	*next_y;
}					t_vert;

int		**read_map(int fd);
void    grid_plot(void *mlx, void *win, int **arr);
