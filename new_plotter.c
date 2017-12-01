/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plotter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:19:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/30 21:35:27 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"

void	draw_line(t_init init, t_vect node)
{
	float	theta_line;
	float	pitch;

	if (node.x1 == node.x2 && node.y1 == node.y2)
	{
		mlx_pixel_put(init.mlx, init.win, node.x1,
		node.y1, get_zcolor(node.z1, init, node.color_table));
		return ;
	}
	if (my_abs(node.delta_y) < my_abs(node.delta_x))
	{
		theta_line = (float)node.delta_y / (float)node.delta_x;
		pitch = (float)node.y1 - theta_line * (float)node.x1;
		node.start = node.x1;
		while (node.x1 != node.x2)
		{
			mlx_pixel_put(init.mlx, init.win, node.x1, (int)(theta_line *
			(float)node.x1 + pitch + 0.5),
			get_ptgcolor(node.x1, node.x2, node, init));
			node.x1 = node.x1 + node.theta_x;
		}
	}
	else
	{
		theta_line = (float)node.delta_x / (float)node.delta_y;
		pitch = (float)node.x1 - theta_line * (float)node.y1;
		node.start = node.y1;
		while (node.y1 != node.y2)
		{
			mlx_pixel_put(init.mlx, init.win, (int)(theta_line *
			(float)node.y1 + pitch + 0.5), node.y1,
			get_ptgcolor(node.y1, node.y2, node, init));
			node.y1 = node.y1 + node.theta_y;
		}
	}
	mlx_pixel_put(init.mlx, init.win, node.x2, node.y2,
	get_zcolor(node.z2, init, node.color_table));
}

void	offsetter(t_vect *node, t_init *init)
{
	int	zdelta;

	zdelta = init->z_Max - init->z_Min;
	node->offset_x = 30;
	if (init->W + init->H > zdelta)
		node->grad = 2000 / (init->W + init->H);
	else
		node->grad = 2000 / (zdelta + init->H);
	node->offset_y = ((zdelta + init->H) / 2) * node->grad;
}

void	set_vvector(t_vect *node, t_init *init, int x, int y, int **z)
{
	offsetter(node, init);
	node->x1 = (x + y) * node->grad + node->offset_x;
	node->x2 = (x + y + 1) * node->grad + node->offset_x;
	node->y1 = y * (node->grad / 2) + node->offset_y -
				z[y][x] * node->grad / 2;
	node->y2 = (y + 1) * (node->grad / 2) +
				node->offset_y - z[y + 1][x] * node->grad / 2;
	node->z1 = z[y][x];
	node->z2 = z[y + 1][x];
	node->delta_x = node->x1 - node->x2;
	node->delta_y = node->y1 - node->y2;
	node->delta_z = node->z1 - node->z2;
	if (node->delta_x < 0)
		node->theta_x = 1;
	else
		node->theta_x = -1;
	if (node->delta_y < 0)
		node->theta_y = 1;
	else
		node->theta_y = -1;
	node->color_table = table_set();
}

void	set_hvector(t_vect *node, t_init *init, int x, int y, int **z)
{
	offsetter(node, init);
	node->x1 = (x + y) * node->grad + node->offset_x;
	node->x2 = (x + y + 1) * node->grad + node->offset_x;
	node->y1 = y * (node->grad / 2) +
				node->offset_y - z[y][x] * node->grad / 2;
	node->y2 = y * (node->grad / 2) +
				node->offset_y - z[y][x + 1] * node->grad / 2;
	node->z1 = z[y][x];
	node->z2 = z[y][x + 1];
	node->delta_x = node->x1 - node->x2;
	node->delta_y = node->y1 - node->y2;
	node->delta_z = node->z1 - node->z2;
	if (node->delta_x < 0)
		node->theta_x = 1;
	else
		node->theta_x = -1;
	if (node->delta_y < 0)
		node->theta_y = 1;
	else
		node->theta_y = -1;
	node->color_table = table_set();
}

void	v_lines(t_init init)
{
	int		x;
	int		y;
	t_vect	node;

	x = 0;
	y = 0;
	while (x < init.W)
	{
		while (y + 1 < init.H)
		{
			set_vvector(&node, &init, x, y, init.arr);
			draw_line(init, node);
			y++;
		}
		y = 0;
		x++;
	}
}

void	h_lines(t_init init)
{
	int		x;
	int		y;
	t_vect	node;

	x = 0;
	y = 0;
	while (y < init.H)
	{
		while (x + 1 < init.W)
		{
			set_hvector(&node, &init, x, y, init.arr);
			draw_line(init, node);
			x++;
		}
		x = 0;
		y++;
	}
}

void	grid_plot(t_init init)
{
	z_limits(&init);
	h_lines(init);
	v_lines(init);
	mlx_loop(init.mlx);
}
