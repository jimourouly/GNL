#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);

typedef struct s_node{
	char 			*content;
	struct s_node	*next;
}t_node;

char *get_next_line(int fd);

t_node *ft_find_last_node(t_node *head);
int ft_new_line(t_node *head);
void create_line(char **line, t_node *node);
void free_node(t_node *node);
int ft_strlen(char *str);
void read_add_to_node(int fd, t_node **node);
void add_to_node(t_node **node, char *buffer, int byteread);
void read_line(t_node *node, char **line);
void clean_node(t_node **node);


#endif
