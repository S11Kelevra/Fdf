/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:18:48 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/09 00:06:59 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx/mlx.h"

int	my_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	else
		return(n);
}

void	plot_node(void *mlx, void *win, int x, int y, int z)
{
	int X;
	int Y;
	int tmp;

	tmp = z;
	X = 0;
	Y = 0;
	while (Y < 4)
	{
		X = 0;
		while(X < 4)
		{
			mlx_pixel_put(mlx, win, x + X, y + Y, 0x000000FF + z * 10);
			X++;
		}
		Y++;
	}
}

void	draw_line(void *mlx, void *win, int x, int y , int X, int Y, unsigned long color)
{
	int delta_x;
	int delta_y;
	int theta_x;
	int theta_y;
	float theta_line;
	float pitch;

	if (x == X && y == Y)
	{
		mlx_pixel_put(mlx, win, x, y, color);
		return;
	}
	delta_x = x - X;
	if (delta_x < 0)
		theta_x = 1;
	else
		theta_x = -1;
	delta_y = y - Y;
	if(delta_y < 0)
		theta_y = 1;
	else
		theta_y = -1;
	unsigned long test;
	test = BLUE;

	printf("delta X:%i\ndelta Y:%i\n", delta_x, delta_y);
	printf("theta X:%i\ntheta Y:%i\n", theta_x, theta_y);

	if (my_abs(delta_y) < my_abs(delta_x))
	{
		theta_line = (float)delta_y / (float)delta_x;
		pitch =  (float)y - theta_line * (float)x;
		printf("Theta line:%f\nPitch line:%f\n", theta_line, pitch);
		while (x != X)
		{
			printf("Placing (%i,%f)\n", x, (theta_line * (float)x + pitch + 0.5));
			mlx_pixel_put(mlx, win, x, (int)((float)theta_line * (float)x + pitch + 0.5), color >> x);
			x = x + theta_x;
			printf("New x:%i\n", x);
		}
	}
	else
	{
		theta_line = (float)delta_x / (float)delta_y;
		pitch = (float)x - theta_line * (float)y;
		printf("Theta line:%f\nPitch line:%f\n", theta_line, pitch);
		while (y != Y)
		{
			printf("Placing (%i,%i)\n", (int)(theta_line * (float)y + pitch + 0.5), y);
			mlx_pixel_put(mlx, win, (int)(theta_line * (float)y + pitch + 0.5), y, RED + GREEN + BLUE - (y * ONE));
			y = y + theta_y;
			printf("New y:%i\n", y);
		}
	}
	printf("last pixel->");
	mlx_pixel_put(mlx, win, X, Y, color);
	printf("placed!\n");
}

void	grid_plot(void *mlx, void *win, int **arr)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = arr[x][y];
	while(y < g_H)
	{
		x = 0;
		while (x < g_W)
		{
			plot_node(mlx, win, x * 5, y * 5, arr[y][x]);
			x++;
		}
		y++;
	}
/*	draw_line(mlx, win, 10, 10, 10, 500, WHITE);
	draw_line(mlx, win, 11, 11, 11, 501, WHITE);
	draw_line(mlx, win, 12, 12, 12, 502, WHITE);
	draw_line(mlx, win, 13, 13, 13, 503, WHAT);
	draw_line(mlx, win, 14, 14, 14, 504, WHAT);
	draw_line(mlx, win, 15, 15, 15, 505, WHAT);
	draw_line(mlx, win, 16, 16, 16, 506, WHAT);
	draw_line(mlx, win, 17, 17, 17, 507, WHITE);
	*/
	mlx_loop(mlx);
}
