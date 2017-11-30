/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/29 21:06:44 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx/mlx.h"

void    draw_line(void *mlx, void *win, int x, int y , int X, int Y);

int	main(int argc, char **argv)
{
	int fd;
	int **arr;
    void    *mlx;
    void    *win;
    
	mlx = mlx_init();
    win = mlx_new_window(mlx, 2000, 2000, "Testing");
	fd = argc;
	fd = open(argv[1], O_RDONLY);
	printf("Fd: %i\n", fd);
	arr = read_map(fd);
	close(fd);
	printf("Plotting\n");
	grid_plot(mlx, win, arr);
	return(0);
}
