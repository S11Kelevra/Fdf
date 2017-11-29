/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 01:18:48 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/21 15:36:28 by eramirez         ###   ########.fr       */
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

void	z_max(int **arr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	g_zMax = 0;
	g_zMin = 0;
	while(y < g_H)
	{
		while (x < g_W)
		{
			if (g_zMax < arr[y][x])
				g_zMax = arr[y][x];
			if(g_zMin > arr[y][x]);
				g_zMin = arr[y][x];
			x++;
		}
		y++;
		x = 0;
	}
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


float	percent(int z, int Z, int start, int stop, int delta)
{
	int Zmax;
	float color;
	float PTG;
	int delta_z;
	float slope;

	Zmax = g_zMax;
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
	float PTG;
	
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
			PTG = percent(z, Z, x, X, my_abs(delta_x));
			mlx_pixel_put(mlx, win, x, (int)(theta_line * (float)x + pitch + 0.5),
					color + (BLUE * ((float)z/(float)g_zMax)) + (BLUE * PTG));
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
			PTG = my_color(z, Z, y, Y, my_abs(delta_y));
			mlx_pixel_put(mlx, win, (int)(theta_line * (float)y + pitch + 0.5), y,
				color + (BLUE * ((float)z/(float)g_zMax)) + (BLUE * PTG));
			y = y + theta_y;
		}
	}
	mlx_pixel_put(mlx, win, X, Y, color);
}

void	h_lines(void *mlx, void* win, int grad, int offset, int **arr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < g_H)
	{
		while (x + 1 < g_W)
		{
			draw_line(mlx, win, (x+y) * grad/2 + offset, (y * grad)/2 + offset - arr[y][x] * grad + grad * g_zMax, arr[y][x],
								(x + 1 + y) * grad/2 + offset, (y * grad)/2 + offset - arr[y][x+1] * grad + grad * g_zMax, arr[y][x+1], RED);
			x++;
		}
		y++;
		x = 0;
	}
}

void	v_lines(void *mlx, void *win, int grad, int offset, int **arr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < g_W)
	{
		while (y + 1 < g_H)
		{
			draw_line(mlx, win, ((x+y) * grad/2 + offset), (y * grad)/2 + offset - arr[y][x] * grad + grad * g_zMax, arr[y][x],
								(x+y+1) * grad/2 + offset, ((y + 1) * grad)/2 + offset - arr[y+1][x] * grad + grad * g_zMax, arr[y+1][x], RED);
			y++;
		}
		x++;
		y = 0;
	}
}

int mmax(int a, int b, int c)
{
	int tmp;

	tmp = 0;
	if (a > tmp)
		tmp = a;
	if (b > tmp)
		tmp = b;
	if (c > tmp)
		tmp = c;
	return(tmp);
}
void	frame_plot(void *mlx, void *win, int **arr)
{
	int grad;
	int offset;

	z_minmax(arr);
	grad = 1000 / mmax(g_H, g_W, g_zMax);
	offset = 10;
	v_lines(mlx, win, grad, offset, arr);
	h_lines(mlx, win, grad, offset, arr);
}

void	grid_plot(void *mlx, void *win, int **arr)
{
	frame_plot(mlx, win, arr);
	mlx_loop(mlx);
}


