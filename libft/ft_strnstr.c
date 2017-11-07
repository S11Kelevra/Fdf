/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:00:32 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:08:36 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		result;
	char	*copy;

	copy = ft_strnew(len);
	ft_strncpy(copy, (char *)big, len);
	result = ft_strstri(copy, little);
	if (result == -1)
		return (NULL);
	else
		return ((char *)&big[result]);
}
