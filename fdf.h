/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:17:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/07 14:54:58 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>

typedef struct      s_rows
{
    char            **split_line;
    struct s_rows   *next;
    int             *array;
    int             elem;
}					t_rows;

int **read_map(int fd);
