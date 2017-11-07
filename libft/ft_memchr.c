/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:06:16 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 19:19:18 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*str;

	find = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == find)
			return (str);
		str++;
		n--;
	}
	return (0);
}
