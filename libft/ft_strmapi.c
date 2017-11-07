/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 18:00:47 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:13:44 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mpstr;
	char			*str;
	int				size;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (0);
	i = 0;
	str = (char *)s;
	size = ft_strlen(s);
	if (!(mpstr = ft_strnew(size)))
		return (0);
	while (str[i])
	{
		mpstr[i] = f(i, s[i]);
		i++;
	}
	return (mpstr);
}
