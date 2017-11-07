/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:57:14 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:03:54 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *src)
{
	char *copy;

	if (!(copy = ft_strnew(ft_strlen(src))))
		return (0);
	ft_strcpy(copy, src);
	return (copy);
}
