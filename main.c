#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_node
{
    char    node_buffer[6];
    struct s_node *next;
}t_node;

int main(void)
{
    int fd;
    char *charread;
    size_t count;
    int BUFFER_SIZE;
    int i;


    i = 0;
    BUFFER_SIZE = 42;

    count = 5;
    charread = malloc(BUFFER_SIZE + 1);
    fd = open("file.txt", O_RDONLY);

    while(i < 10)
    {
        read(fd, charread, count); 
        printf("%s", charread);
        i ++;
    }
}
