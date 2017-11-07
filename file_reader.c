/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:20:28 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/06 22:50:08 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/includes/libft.h"
#include <stdlib.h>

typedef struct		s_rows
{
	char 			**split_line;
	struct s_rows	*next;
	int 			*array;
	int				elem;
}					t_rows;

t_rows 	*start_read(char *line)
{
	int i;
	t_rows *temp;

	i = ft_dlnwordcount(line, ' ');
	temp = (t_rows *)malloc(sizeof(t_rows));
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

void read_map(int fd, char *map)
{
	int H;
	int W;
	char *line;
	char **string;
	int i;
	int j;
	int k;
	t_rows	*head;
	t_rows	*temp;

	i = 0;
	j = 0;
	k = 0;
	H = 0;
	W = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if(i == 0)
			head = start_read(line);
		else
			add_read(head, line);
		i++;
	}
	temp = head;
	while (k < i)
	{	
		j = -1;
		while(temp->split_line[++j])
			printf("%s  ", temp->split_line[j]);
		printf("\n");
		temp = temp->next;
		k++;
	}
	temp = head;
	printf("\nX elements = %i\n", i);
	k = 0;
	while (k < i)
	{	
		j = -1;
		while(temp->split_line[++j])
			printf("%i -", temp->array[j]);
		printf("\n");
		temp = temp->next;
		k++;
	}
}
