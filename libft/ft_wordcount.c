/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:43:55 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:34:56 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_wordcount(char const *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_iswhsp(str[i]) == 0 &&
				(str[i + 1] == 0 || ft_iswhsp(str[i + 1]) == 1))
		{
			i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}
