/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:11:17 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/27 19:57:54 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	remainder;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd('8', fd);
			return ;
		}
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		remainder = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(remainder + 48, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd);
}
