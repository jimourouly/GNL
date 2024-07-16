/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:05:23 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/16 15:17:35 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_char	*node;
	char				*line;
	int					i;

	if (read(fd, &line, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free_node(node);
		node = NULL;
		return (NULL);
	}
	line = NULL;
	read_add_to_node(fd, &node);
	if (node == NULL)
		return (NULL);
	read_line(node, &line);
	i = clean_node(&node, 0, 0);
	if (line == NULL || line[0] == '\0' || (i == 0))
	{
		free_node(node);
		free(line);
		node = NULL;
		return (NULL);
	}
	return (line);
}

//read file and add the content to buffer
void	read_add_to_node(int fd, t_list_char **node)
{
	char	*buffer;
	ssize_t	byteread;

	byteread = 1;
	while (!ft_new_line(*node) && byteread != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		byteread = (int)read(fd, buffer, BUFFER_SIZE);
		if (*node == NULL && byteread <= 0)
		{
			byteread = 0;
			free(buffer);
			free_node(*node);
			return ;
		}
		buffer[byteread] = '\0';
		add_to_node(node, buffer, byteread);
		free(buffer);
	}
}

//add whats in my buffer into last nod
void	add_to_node(t_list_char **node, char *buffer, int byteread)
{
	int			i;
	t_list_char	*lastnode;
	t_list_char	*newnode;

	newnode = malloc(sizeof(t_list_char));
	if (newnode == NULL)
		return ;
	newnode->next = NULL;
	newnode->cont = malloc(sizeof(char) * (byteread + 1));
	if (newnode->cont == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < byteread)
	{
		newnode->cont[i] = buffer[i];
		i++;
	}
	newnode->cont[i] = '\0';
	if (*node == NULL)
	{
		*node = newnode;
		return ;
	}
	lastnode = ft_find_last_node(*node);
	lastnode->next = newnode;
}

//copy char from node and store them in line
void	read_line(t_list_char *node, char **line)
{
	int	i;
	int	j;

	if (node == NULL)
		return ;
	create_line(line, node);
	if (*line == NULL)
		return ;
	j = 0;
	while (node)
	{
		i = 0;
		while (node->cont[i])
		{
			if (node->cont[i] == '\n')
			{
				(*line)[j++] = node->cont[i];
				break ;
			}
			(*line)[j++] = node->cont[i++];
		}
		node = node->next;
	}
	(*line)[j] = '\0';
}

//clean already read characteres, keep the unread char
int	clean_node(t_list_char **node, int i, int j)
{
	t_list_char	*last;
	t_list_char	*temp;

	temp = malloc(sizeof(t_list_char));
	if (node == NULL || temp == NULL)
		free(temp);
	if (node == NULL || temp == NULL)
		return (0);
	temp->next = NULL;
	last = ft_find_last_node(*node);
	while (last->cont[i] && last->cont[i] != '\n')
		i++;
	if (last->cont[i] && last->cont[i] == '\n')
		i++;
	temp->cont = malloc(sizeof(char) * ((ft_strlen_int(last->cont) - i) + 1));
	if (temp->cont == NULL)
		free(temp);
	if (temp->cont == NULL)
		return (0);
	while (last->cont[i])
		temp->cont[j++] = last->cont[i++];
	temp->cont[j] = '\0';
	free_node(*node);
	*node = temp;
	return (1);
}
