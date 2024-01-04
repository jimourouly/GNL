#include "get_next_line.h"

//return last node
t_node *ft_find_last_node(t_node *head)
{
    if (head == NULL)
        return (NULL);
    while (head->next != NULL)
        head=head->next;
    return (head);
}

//return 1 if new line is found
int ft_new_line(t_node *head)
{
    int i;
    t_node  *temp;

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
void create_line(char **line, t_node *node)
{
    int i;
    int len;

    len = 0;
    while(node)
    {
        i = 0;
        while (node->content[i])
        {
            if (node->content[i] == '\n')
            {
                len ++;
                break;
            }
            len ++;
            i++;
        }
        node = node->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
}

//free all my linked list
void free_node(t_node *node)
{
    t_node  *current;
    t_node  *next;

    current = node;
    while(current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;
    }
}

//return how long is a char
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}
