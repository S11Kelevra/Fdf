/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/08 19:14:00 by eramirez         ###   ########.fr       */
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
    win = mlx_new_window(mlx, 1000, 1000, "Testing");
	fd = argc;
	fd = open(argv[1], O_RDONLY);
	printf("Fd: %i\n", fd);
	arr = read_map(fd);
	close(fd);
	grid_plot(mlx, win, arr);
	printf("drawing line\n");
	draw_line(mlx, win, 10, 10, 50, 50);
	//mlx_loop(mlx);
	return(0);
}
