/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:13:04 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/28 22:14:13 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		temp->content = 0;
		temp->content_size = 0;
	}
	else
	{
		if (!(temp->content = malloc(content_size)))
			return (0);
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = 0;
	return (temp);
}
