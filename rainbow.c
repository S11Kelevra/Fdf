/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:23:38 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/29 23:22:09 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "minilibx/mlx.h"
#include <stdlib.h>

void table_set()
{
	int i;
	UL	color;

	i = 0;
	color = 0xFF;
	color_table = (UL *)malloc(sizeof(UL) * 512);
	while (color <= BLUE + GREEN)
	{
		color_table[i] = color;
		color = color + 0x100;
		i++;
	}
	color = BLUE + GREEN;
	while (color >= GREEN)
	{
		color_table[i] = color;
		color = color - 0x1;
		i++;
	}
}

int my_abs(int n)
{
	if (n < 0)
		return(n * -1);
	else
		return(n);
}

UL	get_ptgcolor(int a, int start, int stop, t_vect node, int delta_z)
{
	float	slope;
	float	PTG;
	float	CurrentZ;

	if (node.z1 < node.z2)
		slope = 1.0;
	else
		slope = -1.0;
	CurrentZ = (float)(node.z1 - g_zMin);
	PTG = (CurrentZ + slope * ((float)my_abs(a - stop)/(float)my_abs(start - stop)) *
			(float)my_abs(delta_z)) / (float)(g_zMax - g_zMin);
	return(color_table[(int)(511.0 * PTG)]);
}

UL get_zcolor(int z)
{
	float	tz;
	float	tZmax;
	tz = (float)(z - g_zMin);
	tZmax = (float)(g_zMax - g_zMin);
	return(color_table[(int)(511.0 * (tz/tZmax))]);
}

void    z_minmax(int **arr)
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
            if(g_zMin > arr[y][x])
                g_zMin = arr[y][x];
            x++;
        }
        y++;
        x = 0;
    }
	if (g_zMax == 0)
		g_zMax++;
}
