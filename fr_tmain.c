/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_tmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:39:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/06 19:50:54 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./libft/includes/libft.h"
#include <stdio.h>

void read_map(int fd, char *map);

int	main(int argc, char **argv)
{
	int fd;
	char *map;

	fd = open(argv[1], O_RDONLY);
	printf("Fd: %i\n", fd);
	read_map(fd, map);
	close(fd);
	return(0);
}
