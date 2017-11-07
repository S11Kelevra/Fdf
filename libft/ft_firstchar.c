/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:04:12 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:42:57 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_firstchar(const char *str)
{
	int i;

	i = 0;
	while (ft_iswhsp(str[i]) == 1 && str[i])
		i++;
	return (i);
}
