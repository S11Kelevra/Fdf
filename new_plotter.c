/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plotter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:19:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/29 23:14:27 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"


void draw_line(void *mlx, void *win, t_vect node)
{
	float theta_line;
	float pitch;

	if (node.delta_z != 0)
	//printf("Delta_z for this node = %i\n", node.delta_z);
    if (node.x1 == node.x2 && node.y1 == node.y2)
    {
        mlx_pixel_put(mlx, win, node.x1, node.y1, get_zcolor(node.z1));
        return;
    }
	//printf("Line start\n");
	if (my_abs(node.delta_y) < my_abs(node.delta_x))
    {
		//printf("Using x!\n");
        theta_line = (float)node.delta_y / (float)node.delta_x;
        pitch =  (float)node.y1 - theta_line * (float)node.x1;
		node.start = node.x1;
        while (node.x1 != node.x2)
        {
            mlx_pixel_put(mlx, win, node.x1, (int)(theta_line * (float)node.x1 + pitch + 0.5),
                    get_ptgcolor(node.x1, node.x2, node.start, node, node.delta_z));
            node.x1 = node.x1 + node.theta_x;
        }
    }
    else
    {
		//printf("Using y!\n");
        theta_line = (float)node.delta_x / (float)node.delta_y;
        pitch = (float)node.x1 - theta_line * (float)node.y1;
		node.start = node.y1;
        while (node.y1 != node.y2)
        {
            mlx_pixel_put(mlx, win, (int)(theta_line * (float)node.y1 + pitch + 0.5), node.y1,
                get_ptgcolor(node.y1, node.y2, node.start, node, node.delta_z));
            node.y1 = node.y1 + node.theta_y;
        }
    }
	mlx_pixel_put(mlx, win, node.x2, node.y2, get_zcolor(node.z2));
	//printf("Line done\n");
}

void set_vvector(t_vect *node, int x, int y, int **z)
{
	int grad;
	int offset;

	grad = 30;
	offset = 100;
	node->x1 = (x + y) * grad + offset;
	node->x2 = (x + y + 1) * grad + offset;
	node->y1 = y * (grad/2) + offset - z[y][x] * grad/2;
	node->y2 = (y + 1) * (grad/2) + offset - z[y + 1][x] * grad/2;;
	node->z1 = z[y][x];
	node->z2 = z[y + 1][x];
	node->delta_x = node->x1 - node->x2;
	node->delta_y = node->y1 - node->y2;
	node->delta_z = node->z1 - node->z2;
	if (node->delta_x < 0)
        node->theta_x = 1;
    else
        node->theta_x = -1;
    if(node->delta_y < 0)
        node->theta_y = 1;
    else
        node->theta_y = -1;
}

void set_hvector(t_vect *node, int x, int y, int **z)
{
	int grad;
	int offset;

	grad = 30;
	offset = 100;
	node->x1 = (x + y) * grad + offset;
	node->x2 = (x + y + 1) * grad + offset;
	node->y1 = y * (grad/2) + offset - z[y][x] * grad/2;
	node->y2 = y * (grad/2) + offset - z[y][x + 1] * grad/2;;
	node->z1 = z[y][x];
	node->z2 = z[y][x + 1];
	node->delta_x = node->x1 - node->x2;
	node->delta_y = node->y1 - node->y2;
	node->delta_z = node->z1 - node->z2;
	if (node->delta_x < 0)
        node->theta_x = 1;
    else
        node->theta_x = -1;
    if(node->delta_y < 0)
        node->theta_y = 1;
    else
        node->theta_y = -1;
}

void v_lines(void *mlx, void *win, int **arr)
{
	int x;
	int y;
	t_vect node;

	x = 0;
	y = 0;
	//printf("g_H = %i, g_W = %i\n", g_H, g_W);
	while (x < g_W)
	{
		while(y + 1 < g_H)
		{
			//printf("Setting (%i,%i,%i)\n", x, y, arr[y][x]);
			set_vvector(&node, x, y, arr);
			draw_line(mlx, win, node);
			y++;
		}
		y = 0;
		x++;
	}
}

void h_lines(void *mlx, void *win, int **arr)
{
	int x;
	int y;
	t_vect node;

	x = 0;
	y = 0;
	while (y < g_H)
	{
		while(x + 1 < g_W)
		{
			//printf("Setting (%i,%i,%i)\n", x, y, arr[y][x]);
			set_hvector(&node, x, y, arr);
			draw_line(mlx, win, node);
			x++;
		}
		x = 0;
		y++;
	}
}

void	grid_plot(void *mlx, void *win, int **arr)
{
	//printf("Setting Z's mM\n");
	table_set();
	z_minmax(arr);
	//printf("Set\nDrawing Lines\n");
	h_lines(mlx, win, arr);
	v_lines(mlx, win, arr);
	mlx_loop(mlx);
}	
