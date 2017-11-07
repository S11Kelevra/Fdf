/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:26:06 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/28 22:11:46 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *dlst;

	if (alst == 0)
		return ;
	dlst = *alst;
	while (dlst)
	{
		temp = dlst->next;
		ft_lstdelone(&dlst, del);
		dlst = temp;
	}
	*alst = 0;
	return ;
}
