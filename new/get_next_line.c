#include "get_next_line.h"

char	*get_next_line(int fd)
{
	printf("GET_NEXT_LINE\n");
	static t_list	*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	node = NULL;
	line = NULL;
	read_add_to_node(fd, &node);
	if (node == NULL)
		return (NULL);
	read_line(node, &line);
	clean_node(&node);
	if (line[0] == '\0')
	{
		free_node(node);
		node = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

//copy char in linkedlist
void	read_add_to_node(int fd, t_list **node)
{
	printf("READ_ADD_TO_NODE\n");
	char	*buffer;
	int		byteread;

	byteread = 1;
	while (!ft_new_line(*node) && byteread != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
		if (!buffer)
			return ;
		byteread = read(fd, buffer, BUFFER_SIZE);
		if ((!*node && byteread == 0) || byteread < 0)
		{
			free (buffer);
			return ;
		}
		buffer[byteread] = '\0';
		add_to_node(node, buffer, byteread);
		free (buffer);
	}
}

//add whats in my buffer into linked list node
void	add_to_node(t_list **node, char *buffer, int byteread)
{
	printf("ADD_TO_NODE\n");
	int		i;
	t_list	*lastnode;
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return ;
	newnode->next = NULL;
	newnode->content = malloc(sizeof(char) * (byteread + 1));
	if (newnode->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < byteread)
	{
		newnode->content[i] = buffer[i];
		i++;
	}
	newnode->content[i] = '\0';
	if (*node == NULL)
	{
		*node = newnode;
		return ;
	}
	lastnode = ft_find_last_node(*node);
	lastnode->next = newnode;
}

//copy char from node and store them in line
void	read_line(t_list *node, char **line)
{
	printf("READ_LINE\n");
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
		while (node->content[i])
		{
			if (node->content[i] == '\n')
			{
				(*line)[j] = node->content[i];
				j ++;
				break ;
			}
			(*line)[j++] = node->content[i++];
		}
		node = node->next;
	}
	(*line[j] = '\0');
}

//clean already read characteres, keep the unread char
void	clean_node(t_list **node)
{
	printf("CLEAN_NODE\n");
	t_list	*last;
	t_list	*temp;
	int		i;
	int		j;

	temp = malloc(sizeof(t_list));
	if (node == NULL || temp == NULL)
		return ;
	temp->next = NULL;
	last = ft_find_last_node(*node);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
	{
		printf("_____________\nlast->content[%d] = :%c:\n____________\n", i, last->content[i]);
		i++;
	}
	if (last->content && last->content[i] == '\n')
		i++;
	temp->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (temp->content == NULL)
		return ;
	j = 0;
	printf("\t\tlast->content = :%s:\n", last->content);
	while (last->content[i])
		temp->content[j++] = last->content[i++];
	temp->content[j] = '\0';
	free_node(*node);
	*node = temp;
}
