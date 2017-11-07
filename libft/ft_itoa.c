/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:13:46 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:25:34 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_itoa(int n)
{
	int		lendiggies;
	int		neg;
	int		flip;
	char	*datascii;

	flip = 1;
	neg = 1;
	lendiggies = ft_lendigits(n);
	if (n < 0)
	{
		flip = -1;
		neg = 0;
		if (!(datascii = ft_strnew(lendiggies + 1)))
			return (0);
		datascii[0] = '-';
	}
	else if (!(datascii = ft_strnew(lendiggies)))
		return (0);
	while (lendiggies-- > 0)
	{
		datascii[lendiggies - neg + 1] = flip * (n % 10) + 48;
		n /= 10;
	}
	return (datascii);
}
