#include "get_next_line.h"

//return last node
t_list	*ft_find_last_node(t_list *head)
{
	printf("FT_FIND_LAST_NODE\n");
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

//return 1 if new line is found
int	ft_new_line(t_list *head)
{
	printf("FT_NEW_LINE\n");
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
	printf("CREATE_LINE\n");
	int	i;
	int	len;

	len = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			printf("\n---------\nnode->content[%d] = :%c:\n", i, node->content[i]);
			if (node->content[i] == '\n')
			{
				len ++;
				break ;
			}
			len ++;
			i++;
			printf("\n i=:%d:\t len=:%d:\n------", i, len);
		}
		node = node->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	printf("\n line=:%s:", *line);
}

//free all my linked list
void	free_node(t_list *node)
{
	printf("FREE_NODE\n");
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
int	ft_strlen(char *str)
{
	printf("FT_STRLEN\n");
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
