/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:23:38 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 18:59:43 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"

UL		*table_set(void)
{
	int	i;
	UL	color;
	UL	*color_table;

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
	return (color_table);
}

UL		get_ptgcolor(int a, int start, t_vect node, t_init init)
{
	float	slope;
	float	ptg;
	float	current_z;

	if (node.z1 < node.z2)
		slope = 1.0;
	else
		slope = -1.0;
	current_z = (float)(node.z1 - init.z_Min);
	ptg = (current_z + slope * ((float)abs(a - node.start) /
			(float)abs(start - node.start)) *
			(float)abs(node.delta_z)) / (float)(init.z_Max - init.z_Min);
	return (node.color_table[(int)(511.0 * ptg)]);
}

UL		get_zcolor(int z, t_init init, UL *color_table)
{
	float	tz;
	float	tzmax;

	tz = (float)(z - init.z_Min);
	tzmax = (float)(init.z_Max - init.z_Min);
	return (color_table[(int)(511.0 * (tz / tzmax))]);
}

void	z_limits(t_init *param)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	param->z_Max = 0;
	param->z_Min = 0;
	while (y < param->H)
	{
		while (x < param->W)
		{
			if (param->z_Max < param->arr[y][x])
				param->z_Max = param->arr[y][x];
			if (param->z_Min > param->arr[y][x])
				param->z_Min = param->arr[y][x];
			x++;
		}
		y++;
		x = 0;
	}
	if (param->z_Max == 0)
		param->z_Max++;
}
