/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:17:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 21:38:04 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

# define UL		unsigned long

typedef struct		s_rows
{
	char			**split_line;
	struct s_rows	*next;
	int				*array;
	int				elem;
}					t_rows;

typedef struct		s_vect
{
	int				start;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				offset_x;
	int				offset_y;
	int				grad;
	int				delta_x;
	int				delta_y;
	int				delta_z;
	int				theta_x;
	int				theta_y;
	UL				*color_table;
}					t_vect;

typedef struct		s_index
{
	int				i;
	int				j;
	int				x;
	int				y;
}					t_index;

typedef struct		s_init
{
	int				H;
	int				W;
	int				fd;
	int				z_Min;
	int				z_Max;
	int				**arr;
	void			*win;
	void			*mlx;
}					t_init;

int		checkmap(t_rows *head);
int		read_map(t_init *init);
void	grid_plot(t_init param);
UL		get_ptgcolor(int a, int stop, t_vect node, t_init init);
UL		get_zcolor(int z, t_init init, UL *color_table);
int		my_abs(int n);
void	z_limits(t_init *init);
UL		*table_set(void);
void	draw_line(t_init init, t_vect node);
void	offsetter(t_vect *node, t_init *init);
void	h_lines(t_init init);
void	v_lines(t_init init);

#endif
