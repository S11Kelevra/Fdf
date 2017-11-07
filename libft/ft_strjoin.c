/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:23:36 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:15:02 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*joined;

	if (s1 == 0 && s2 == 0)
		return (ft_strnew(0));
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	if (!(joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	i = ft_strlen(s1);
	ft_memmove(joined, s1, i);
	ft_memmove(&joined[i], s2, ft_strlen(s2));
	return (joined);
}
