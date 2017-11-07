/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/07 14:58:09 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;
	int **arr;

	fd = argc;
	fd = open(argv[1], O_RDONLY);
	printf("Fd: %i\n", fd);
	arr = read_map(fd);
	close(fd);
	return(0);
}
