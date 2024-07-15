/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:46 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/15 15:54:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return last node
t_list_char	*ft_find_last_node(t_list_char *head)
{
	t_list_char	*current;

	current = head;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

//return 1 if new line is found
int	ft_new_line(t_list_char *head)
{
	int			i;
	t_list_char	*temp;

	if (head == NULL)
		return (0);
	temp = ft_find_last_node(head);
	i = 0;
	while (temp->cont[i])
	{
		if (temp->cont[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//calculate char in line and malloc for the right size
void	create_line(char **line, t_list_char *node)
{
	int	i;
	int	len;

	len = 0;
	while (node)
	{
		i = 0;
		while (node->cont[i])
		{
			if (node->cont[i] == '\n')
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
void	free_node(t_list_char *node)
{
	t_list_char	*current;
	t_list_char	*next;

	current = node;
	while (current)
	{
		free(current->cont);
		next = current->next;
		free(current);
		current = next;
	}
}

//return how long is a char
int	ft_strlen_int(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
