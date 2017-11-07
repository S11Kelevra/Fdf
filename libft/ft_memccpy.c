/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:39:58 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 19:20:17 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tdst;
	unsigned char *tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	while (n-- > 0)
	{
		if ((*tdst++ = *tsrc++) == (unsigned char)c)
			return (tdst);
	}
	return (0);
}
