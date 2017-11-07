/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:32:06 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/28 22:13:28 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *ilst;

	if (lst)
	{
		temp = f(lst);
		if (!(ilst = temp))
			return (0);
		while (lst->next)
		{
			lst = lst->next;
			temp->next = f(lst);
			if (!(temp->next))
				return (0);
			temp = temp->next;
		}
		return (ilst);
	}
	else
		return (0);
}
