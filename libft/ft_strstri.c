/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:57:03 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:02:15 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strstri(const char *big, const char *little)
{
	int		i;
	int		limit;
	int		littlen;
	char	*loc;

	loc = (char *)big;
	i = 0;
	limit = ft_strlen(big);
	littlen = ft_strlen(little);
	if (!little)
		return (-1);
	while (i <= limit)
	{
		if (ft_strncmp(&big[i], little, littlen) == 0)
			return (i);
		i++;
	}
	return (-1);
}
