/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:17:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/29 22:31:04 by eramirez         ###   ########.fr       */
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
# define UL		unsigned long
int g_H;
int g_W;
int g_zMax;
int g_zMin;
UL	*color_table;

typedef struct      s_rows
{
    char            **split_line;
    struct s_rows   *next;
    int             *array;
    int             elem;
}					t_rows;

typedef struct		s_vect
{
	int				start;
	int				x1;
	int				x2;
	int 			y1;
	int 			y2;
	int				z1;
	int				z2;
	int				delta_x;
	int				delta_y;
	int				delta_z;
	int				theta_x;
	int				theta_y;
}					t_vect;

typedef struct		s_vert
{
	int 			x;
	int				y;
	int				z;
	struct s_vert	*next;
}					t_vert;

int		**read_map(int fd);
void    grid_plot(void *mlx, void *win, int **arr);
UL		get_ptgcolor(int a, int stop, int start, t_vect node, int delta_z);
UL		get_zcolor(int z);
int		my_abs(int n);
void    z_minmax(int **arr);
void	table_set();
