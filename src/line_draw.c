/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:19:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 21:26:46 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"

void	draw_x(t_init *init, t_vect *node)
{
	float	theta_line;
	float	pitch;

	theta_line = (float)node->delta_y / (float)node->delta_x;
	pitch = (float)node->y1 - theta_line * (float)node->x1;
	node->start = node->x1;
	while (node->x1 != node->x2)
	{
		mlx_pixel_put(init->mlx, init->win, node->x1, (int)(theta_line *
		(float)node->x1 + pitch + 0.5),
		get_ptgcolor(node->x1, node->x2, *node, *init));
		node->x1 = node->x1 + node->theta_x;
	}
}

void	draw_y(t_init *init, t_vect *node)
{
	float	theta_line;
	float	pitch;

	theta_line = (float)node->delta_x / (float)node->delta_y;
	pitch = (float)node->x1 - theta_line * (float)node->y1;
	node->start = node->y1;
	while (node->y1 != node->y2)
	{
		mlx_pixel_put(init->mlx, init->win, (int)(theta_line *
		(float)node->y1 + pitch + 0.5), node->y1,
		get_ptgcolor(node->y1, node->y2, *node, *init));
		node->y1 = node->y1 + node->theta_y;
	}
}

void	draw_line(t_init init, t_vect node)
{
	if (node.x1 == node.x2 && node.y1 == node.y2)
	{
		mlx_pixel_put(init.mlx, init.win, node.x1,
		node.y1, get_zcolor(node.z1, init, node.color_table));
		return ;
	}
	if (abs(node.delta_y) < abs(node.delta_x))
		draw_x(&init, &node);
	else
		draw_y(&init, &node);
	mlx_pixel_put(init.mlx, init.win, node.x2, node.y2,
	get_zcolor(node.z2, init, node.color_table));
}
