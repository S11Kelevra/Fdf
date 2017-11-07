/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlnwordcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:43:55 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:36:16 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_dlnwordcount(char const *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && (str[i + 1] == 0 || str[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}
