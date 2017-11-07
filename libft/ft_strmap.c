/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:33:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:11:27 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mpstr;
	int		size;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	size = ft_strlen(s);
	if (!(mpstr = ft_strnew(size)))
		return (0);
	while (s[i])
	{
		mpstr[i] = f(s[i]);
		i++;
	}
	return (mpstr);
}
