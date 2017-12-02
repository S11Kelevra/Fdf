/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plotter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:19:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 21:26:49 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"

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

void	set_vvector(t_vect *node, t_init *init, int x, int y)
{
	offsetter(node, init);
	node->x1 = (x + y) * node->grad + node->offset_x;
	node->x2 = (x + y + 1) * node->grad + node->offset_x;
	node->y1 = y * (node->grad / 2) + node->offset_y -
				init->arr[y][x] * node->grad / 2;
	node->y2 = (y + 1) * (node->grad / 2) +
				node->offset_y - init->arr[y + 1][x] * node->grad / 2;
	node->z1 = init->arr[y][x];
	node->z2 = init->arr[y + 1][x];
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

void	set_hvector(t_vect *node, t_init *init, int x, int y)
{
	offsetter(node, init);
	node->x1 = (x + y) * node->grad + node->offset_x;
	node->x2 = (x + y + 1) * node->grad + node->offset_x;
	node->y1 = y * (node->grad / 2) +
				node->offset_y - init->arr[y][x] * node->grad / 2;
	node->y2 = y * (node->grad / 2) +
				node->offset_y - init->arr[y][x + 1] * node->grad / 2;
	node->z1 = init->arr[y][x];
	node->z2 = init->arr[y][x + 1];
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
			set_vvector(&node, &init, x, y);
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
			set_hvector(&node, &init, x, y);
			draw_line(init, node);
			x++;
		}
		x = 0;
		y++;
	}
}
