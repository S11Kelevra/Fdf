/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:33:31 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 19:22:29 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tdst;
	unsigned char *tsrc;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (tdst < tsrc)
	{
		while (len-- > 0)
			*tdst++ = *tsrc++;
	}
	else
	{
		tdst += len;
		tsrc += len;
		while (len-- > 0)
			*--tdst = *--tsrc;
	}
	return (dst);
}
