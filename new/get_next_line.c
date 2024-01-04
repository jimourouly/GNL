#include "get_next_line.h"

char *get_next_line(int fd)
{
    static  t_node   *node;
    char    *line;

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
void read_add_to_node(int fd, t_node **node)
{
    char    *buffer;
    int     byteread;



    byteread = 1;

    while (!ft_new_line(*node) && byteread != 0)
    {
        buffer = malloc(sizeof(char)*(BUFFER_SIZE +1));
        if (!buffer)
            return;
        byteread = read(fd, buffer, BUFFER_SIZE);
        if ((!*node && byteread == 0) || byteread < 0)
        {
            free (buffer);
            return;
        }
        buffer[byteread] = '\0';
        add_to_node(node, buffer, byteread);
        free (buffer);
    }
}

//add whats in my buffer into linked list node
void add_to_node(t_node **node, char *buffer, int byteread)
{
    int i;
    t_node  *lastnode;
    t_node  *newnode;

    newnode = malloc(sizeof(t_node));
    if(newnode == NULL)
        return;
    newnode->next = NULL;
    newnode->content = malloc(sizeof(char) * (byteread + 1));
    if (newnode->content == NULL)
        return;
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
        return;
    }
    lastnode = ft_find_last_node(*node);
    lastnode->next = newnode;
}

//copy char from node and store them in line
void read_line(t_node *node, char **line)
{
    int i;
    int j;

    if(node == NULL)
        return;
    create_line(line, node);
    if (*line == NULL)
        return;
    j = 0;
    while (node)
    {
        i = 0;
        while (node->content[i])
        {
            if (node->content[i] == '\n')
            {
                (*line)[j++] = node->content[i];
                break;
            }
            (*line)[j++] = node->content[i++];
        }
        node = node->next;
    }
    (*line[j] = '\0');
}

//clean already read characteres, keep the unread char
void clean_node(t_node **node)
{
    t_node  *last;
    t_node  *cleanednode;
    int i;
    int j;

    cleanednode = malloc(sizeof(t_node));
    if(node == NULL || cleanednode == NULL)
        return;
    cleanednode->next == NULL;
    last = ft_find_last_node(*node);
    i = 0;
    while (last->content[i] && last->content[i] != '\n')
        i++;
    if (last->content && last->content[i] == '\n')
        i++;
    cleanednode->content = malloc(sizeof(char)* ((ft_strlen(last->content) - i) + 1));
    if (cleanednode->content == NULL)
        return;
    j = 0;
    while (last->content[i])
        cleanednode->content[j++] = last->content[i++];
    cleanednode->content[j] = '\0';
    free_node(*node);
    *node = cleanednode;
}