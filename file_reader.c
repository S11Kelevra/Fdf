/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:20:28 by eramirez          #+#    #+#             */
/*   Updated: 2017/12/01 19:10:16 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_rows	*start_read(char *line)
{
	int		i;
	t_rows	*temp;

	i = ft_dlnwordcount(line, ' ');
	temp = (t_rows *)malloc(sizeof(t_rows));
	temp->elem = ft_dlnwordcount(line, ' ');
	temp->split_line = ft_strsplit(line, ' ');
	temp->array = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (temp->split_line[++i])
		temp->array[i] = ft_atoi(temp->split_line[i]);
	temp->next = NULL;
	return (temp);
}

t_rows	*add_read(t_rows *head, char *line)
{
	t_rows	*temp;
	int		i;

	while (head->next != NULL)
		head = head->next;
	temp = (t_rows *)malloc(sizeof(t_rows));
	temp->elem = ft_dlnwordcount(line, ' ');
	temp->split_line = ft_strsplit(line, ' ');
	temp->array = (int *)malloc(sizeof(int) * temp->elem);
	i = -1;
	while (temp->split_line[++i])
		temp->array[i] = ft_atoi(temp->split_line[i]);
	temp->next = NULL;
	head->next = temp;
	return (temp);
}

int		**list_toarr(t_rows *start, int rows)
{
	int		**arr;
	int		y;
	int		x;
	t_rows	*temp;

	temp = start;
	x = -1;
	y = -1;
	arr = (int **)malloc(sizeof(int*) * rows);
	while (++y < rows)
		arr[y] = (int *)malloc(sizeof(int) * start->elem);
	y = -1;
	while (++y < rows)
	{
		x = -1;
		while (++x < start->elem)
			arr[y][x] = temp->array[x];
		temp = temp->next;
	}
	return (arr);
}

void	index_set(t_index *index)
{
	index->i = 0;
	index->j = 1;
	index->x = -1;
	index->y = -1;
}

int		read_map(t_init *init)
{
	char	*line;
	t_index	index;
	t_rows	*head;
	t_rows	*temp;

	index_set(&index);
	while (get_next_line(init->fd, &line) > 0)
	{
		if (index.i == 0)
			head = start_read(line);
		else
			add_read(head, line);
		index.i++;
	}
	temp = head;
	while (temp->next != NULL)
	{
		index.j++;
		temp = temp->next;
	}
	temp = head;
	init->arr = list_toarr(temp, index.i);
	init->H = index.j;
	init->W = head->elem;
	return(checkmap(head));
}
