/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:47 by jroulet           #+#    #+#             */
/*   Updated: 2023/12/09 16:54:48 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//return last node
t_list	*ft_find_last_node(t_list *head)
{
	t_list	*current;

	current = head;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

//return 1 if new line is found
int	ft_new_line(t_list *head)
{
	int		i;
	t_list	*temp;

	if (head == NULL)
		return (0);
	temp = ft_find_last_node(head);
	i = 0;
	while (temp->content[i])
	{
		if (temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//calculate char in line and malloc for the right size
void	create_line(char **line, t_list *node)
{
	int	i;
	int	len;

	len = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			if (node->content[i] == '\n')
			{
				len ++;
				break ;
			}
			len ++;
			i++;
		}
		node = node->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

//free all my linked list
void	free_node(t_list *node)
{
	t_list	*current;
	t_list	*next;

	current = node;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

//return how long is a char
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
