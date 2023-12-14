/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:26 by jroulet           #+#    #+#             */
/*   Updated: 2023/12/09 21:05:11 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void ft_strcpy(t_node *head, char *buff)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(buff[i] && head->node_buff[j])
    {
        head->node_buff[j] = buff[i];
        j++;
        i++;
    }
}

void ft_onfreetoutca(t_node **head, t_node *new_node, char *buff)
{
	t_node	*temp;

	if (*head == NULL)
	{
		return;
	}
	while (*head)
	{
		temp = (*head)->next;
		free((*head)->node_buff);
		free(*head);
		*head = temp;
	}
	*head = NULL;
	if (new_node->node_buff[0])
		*head = new_node;
	else
	{
		free(buff);
		free(new_node);
        buff = NULL;
        new_node = NULL;
	}
}

int ft_length_node(t_node *head)
{
	int i;
	int len;

	len = 0;
	while(head)
	{
		i = 0;
		while (head->node_buff[i])
		{
			if (head->node_buff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		head = head->next;
	}
	return (len);
}

int ft_found_newligne(t_node *head)
{
	int i;

	if (head == NULL)
	{
		return (0);
	}
	while (head != NULL)
	{
		i = 0;
		while (head->node_buff[i] && i != BUFFER_SIZE)
		{
			if (head->node_buff[i] == '\n')
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}

t_node *ft_find_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

void	ft_node_insert_to_end(t_node **head, char *buff)
{
	t_node	*lastnode;
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	lastnode = ft_find_last_node(*head);
	if (newnode == NULL)
		return;
	if (lastnode == NULL)
	{
		*head = newnode;
	}
	else
	{
		lastnode->next = newnode;
	}
    ft_strcpy(newnode, buff);
	newnode->next = NULL;

}

void	ft_create_list(t_node **head, int fd)
{
	int		char_read;
	char	*buff;

	while((ft_found_newligne(*head)) == 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
		{
			return;
		}
		char_read = read(fd, buff, BUFFER_SIZE);
		if (!char_read)
		{
			free (buff);
            buff = NULL;
			return;
		}
		buff[char_read] = '\0';
		ft_node_insert_to_end(head, buff);
	}
}

void ft_copy_node(t_node *head, char *str)
{
	int i;
	int j;

	if (head == NULL)
		return;
	j = 0;
	while (head)
	{
		i = 0;
		while (head->node_buff[i])
		{
			if (head->node_buff[i] == '\n')
			{
				str[j]='\n';
				j++;
				str[j]='\0';
				return ;
			}
			str[j] = head->node_buff[i];
			j++;
			i++;
		}
		head = head->next;
	}
	str[j] = '\0';
}

char *ft_create_line(t_node *head)
{
	int		len;
	char	*next;

	if (head == NULL)
		return (NULL);
	len = ft_length_node(head);
	next = malloc(len + 1);
	if (next == NULL)
		return (NULL);

	ft_copy_node(head, next);
	return (next);

}

void ft_cleaning(t_node **head)
{
	t_node	*old_node;
	t_node	*new_node;
	int i;
	int j;
	int k;
	char *buff;

	i = 0;
	j = 0;

	buff = malloc(BUFFER_SIZE +1);
	new_node = malloc(sizeof(t_node));
	if (buff == NULL || new_node == NULL)
		return;
	old_node = ft_find_last_node(*head);

	while (old_node->node_buff[i] != '\0' && old_node->node_buff[i] != '\n')
	{
		i++;
	}
	while (old_node->node_buff[i])
	{
		buff[k] = old_node->node_buff[i];
		k++;
		i++;
	}
	buff[k] = '\0';
    ft_strcpy(new_node, buff);
t s	new_node->next = NULL;
	ft_onfreetoutca(head, new_node,buff);
}

char *get_next_line(int fd)
{
	static t_node	*node = NULL;
	char			*next;
	int				can_read;

	can_read = read(fd, &next, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || can_read < 0)
		return (NULL);
	ft_create_list(&node, fd);
	if (node == NULL)
		return (NULL);

	next = ft_create_line(node);

	ft_cleaning(&node);

	return (next);



}

int main (void)
{
	int fd;
	char *filename;
	char *str;
	int nbrline;

    nbrline = 0;
	filename = "file.txt";
	fd = open(filename, O_RDONLY);
	if(fd < 0)
    {
        perror("error");
        return (1);
    }
	while (str != get_next_line(fd))
	{
		printf("%d -> %s\n", nbrline, str);
        free(str);
		nbrline ++;
	}
}
