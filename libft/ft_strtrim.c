/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:30:36 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:27:41 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		stop;
	char	*trimmedstr;

	if (!s)
		return (0);
	start = ft_firstchar(s);
	stop = ft_lastchar(s);
	if (start > stop)
		return (ft_strdup(""));
	if (!(trimmedstr = ft_strsub(s, start, (stop - start + 1))))
		return (0);
	return (trimmedstr);
}
