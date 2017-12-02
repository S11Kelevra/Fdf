/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 19:43:39 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx/mlx.h"
#include <strings.h>

int	my_error(int n)
{
	if (n == 1)
		ft_putstr("Usage: ./fdf [path to file]\n");
	if (n == 2)
		ft_putstr("Error: Bad map, missing X elements.\n");
	return(-1);
}

int		checkmap(t_rows *head)
{
	t_rows *tmp;

	tmp = head;
	while(tmp->next != NULL)
	{
		if (head->elem != tmp->elem)
			return(-1);
		tmp = tmp->next;
	}
	return(1);
}

static int	key_hook(int keycode, t_init *init)
{
	if (keycode == 53)
	{
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	return(0);
}


int		main(int argc, char **argv)
{
	t_init init;
    extern int errno;

	if (argc == 1 || argc > 2)
		return(my_error(1));
	if (1 > (init.fd = open(argv[1], O_RDONLY)))
	{
		ft_putstr("Error: ");
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return(-1);
	}
	if (read_map(&init) == -1)
		return(my_error(2));
	init.mlx = mlx_init();
    init.win = mlx_new_window(init.mlx, 2000, 2000, "Fdf");
	mlx_key_hook(init.win, key_hook, &init);
	close(init.fd);
	grid_plot(init);
	return(0);
}
