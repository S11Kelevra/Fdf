/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:07:18 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:07:40 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
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
		return (&loc[i]);
	while (i <= limit)
	{
		if (ft_strncmp(&big[i], little, littlen) == 0)
			return (&loc[i]);
		i++;
	}
	return (NULL);
}
