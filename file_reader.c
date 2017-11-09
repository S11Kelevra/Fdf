/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:20:28 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/08 22:52:03 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_rows 	*start_read(char *line)
{
	int i;
	t_rows *temp;

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

t_rows *add_read(t_rows *head, char *line)
{
	t_rows *temp;
	int i;
	
	while(head->next != NULL)
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

int **list_toarr(t_rows *start, int rows)
{
	int **arr;
	int y;
	int x;
	t_rows *temp;

	g_W = start->elem;
	g_H = rows;
	temp = start;
	x = -1;
	y = -1;
	arr = (int **)malloc(sizeof(int*) * rows);
	printf("line ROW: %i COL: %i\n", rows, start->elem);
	while(++y < rows)
	{
		printf("ROW[%i] COL: %i\n", y, start->elem);
		arr[y] = (int *)malloc(sizeof(int) * start->elem);
	}
	printf("Malloc good!\n");
	y = -1;
	while (++y < rows)
	{	//printf("Starting loop!\n");
		//printf("Elem in this line : %i\n", temp->elem);
		x = -1;
		//printf("arr[0] = %i\n", temp->array[x]);
		//printf("X reset to %i y is %i\n", x, y);
		while (++x < g_W)
		{
			//printf("Adding %i to arr[%i][%i]->", temp->array[x], y, x);
			arr[y][x] = temp->array[x];
			//printf("Added!\n");
		}
		//printf("Moving list\n");
		temp = temp->next;
	}
	return (arr);
}

int **read_map(int fd)
{
	char *line;
	int **arr;
	int i;
	int j;
	int x;
	int y;
	t_rows	*head;
	t_rows	*temp;
	
	i = 0;
	j = 1;
	x = -1;
	y = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if(i == 0)
			head = start_read(line);
		else
			add_read(head, line);
		i++;
	}
	printf("Array size: (%i,%i)\n", head->elem, i);
	temp = head;
	while (temp->next != NULL)
	{
		j++;
		temp = temp->next;
	}
	temp = head;
	printf("Linked list size : %i\n", j);
	arr = list_toarr(temp, i);
	printf("2D array :\n");
	while(++y < i)
	{
		x = - 1;
		while(++x < head->elem)
			printf("%i ", arr[y][x]);
		printf("\n");
	}
	return(arr);
}
