/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:25:25 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:45:13 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_lastchar(const char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (ft_iswhsp(str[i]) == 1 && i > 0)
		i--;
	return (i);
}
