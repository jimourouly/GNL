#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

	printf("%d _BUFFER \n", BUFFER_SIZE);

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (0);
   while(1)
   {

        line = get_next_line(fd);
        if (line == NULL)
           break;
        printf("%s", line);;
        free (line);
   }
    return (0);
}
