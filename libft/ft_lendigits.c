/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lendigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:28:53 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 20:46:10 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_lendigits(int demdigits)
{
	int	digylen;

	digylen = 0;
	if (demdigits == 0)
		return (1);
	while (demdigits != 0)
	{
		demdigits /= 10;
		digylen++;
	}
	return (digylen);
}
