/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:18:48 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/10 00:22:42 by eramirez         ###   ########.fr       */
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


float	my_color(int z, int Z, int start, int stop, int delta)
{
	int Zmax;
	float color;
	float PTG;
	int delta_z;
	float slope;

	Zmax = 10;
	delta_z = z - Z;
	if (z < Z)
		slope = 1.0;
	else
		slope = -1.0;
	if (delta_z == 0)
		return(0.0);
	if (start > stop)
		PTG = -1 * ((float)start - (float)stop - (float)delta)/(float)delta;
	else
		PTG = ((float)start - (float)stop + (float)delta)/(float)delta;
	color = (PTG * my_abs((float)(z - Z)));
	color = color / (float)Zmax;
	//printf("Percent line -> %f\n", PTG);
	printf("Percent color>  %f\n", slope * color);
	return(color * slope);
}
void	draw_line(void *mlx, void *win, int x, int y , int z, int X, int Y, int Z, unsigned long color)
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
	if (my_abs(delta_y) < my_abs(delta_x))
	{
		theta_line = (float)delta_y / (float)delta_x;
		pitch =  (float)y - theta_line * (float)x;
		while (x != X)
		{
		
			mlx_pixel_put(mlx, win, x, (int)(theta_line * (float)x + pitch + 0.5),
					color + (BLUE * ((float)z/10.0)) + (BLUE * my_color(z, Z, x, X, my_abs(delta_x))));
			x = x + theta_x;
			printf("%i\n", x);
		}
	}
	else
	{
		theta_line = (float)delta_x / (float)delta_y;
		pitch = (float)x - theta_line * (float)y;
		while (y != Y)
		{	
			mlx_pixel_put(mlx, win, (int)(theta_line * (float)y + pitch + 0.5), y,
					color + (BLUE * ((float)z/10.0)) + (BLUE * my_color(z, Z, y, Y, my_abs(delta_y))));
			y = y + theta_y;
			//printf("%i\n", y);
		}
	}
	mlx_pixel_put(mlx, win, X, Y, color);
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
	//draw_line(mlx, win, 10, 10, 10, 100, 100, 7, RED);
	//draw_line(mlx, win, 100, 100, 7, 200, 200, 4, RED);
	//draw_line(mlx, win, 200, 200, 4, 300, 300, 1, RED);


	//draw_line(mlx, win, 100, 100, 0, 250, 250, 10, RED);

	draw_line(mlx, win, 550, 500, 0, 350, 300, 10, RED);
	draw_line(mlx, win, 500, 500, 10, 300, 300, 0, RED);

	mlx_loop(mlx);
}
