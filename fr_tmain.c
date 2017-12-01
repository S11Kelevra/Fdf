/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/30 21:35:35 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx/mlx.h"

int	main(int argc, char **argv)
{
	t_init init;
    
	init.mlx = mlx_init();
    init.win = mlx_new_window(init.mlx, 2000, 2000, "Testing");
	init.fd = argc;
	init.fd = open(argv[1], O_RDONLY);
	read_map(&init);
	close(init.fd);
	grid_plot(init);
	return(0);
}
