#ifndef MAIN_H
# define MAIN_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_node
{
    char    node_buffer[BUFFER_SIZE + 1];
    struct  s_node *next;
}t_node;




















#endif
