/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:17:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/09 00:06:57 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>
#include "./minilibx/mlx.h"

# define WHITE	0x00FFFFFF
# define GREEN	0x0000FF00
# define RED	0x00FF0000
# define BLUE	0x000000FF
# define ONE	0x00000001
# define WHAT	0xFFFFFFFF
int g_H;
int g_W;

typedef struct      s_rows
{
    char            **split_line;
    struct s_rows   *next;
    int             *array;
    int             elem;
}					t_rows;

int		**read_map(int fd);
void    grid_plot(void *mlx, void *win, int **arr);
