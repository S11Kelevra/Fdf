/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:51:24 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 21:02:10 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == 0 || n == 1)
			return (0);
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2)
		return ((unsigned char)*s1 - *s2);
	return (0);
}
