#include "main.h"

int main(void)
{
    int fd;
    char *charread;
    size_t count;
    int k;
    int i;
    int j;
    
    
    i = 0;

    count = BUFFER_SIZE;
    charread = malloc(BUFFER_SIZE + 1);
    fd = open("file.txt", O_RDONLY);
    while(i < BUFFER_SIZE)
    {
        k = 0;
        j = read(fd, charread, count);
        while(charread[k] != '\0' && !(j==0))
        {
            if (!(charread[k] == '\n'))
                printf("%c", charread[k]);
            else
            {
                printf("%d \n",j);

            }
            k++;
        }
        i++;

    }
}
