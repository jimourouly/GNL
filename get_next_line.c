/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:26 by jroulet           #+#    #+#             */
/*   Updated: 2023/12/09 18:33:17 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*
char *get_next_line(int fd)
{
	static t_node	*node = NULL;
	t_node			*head;
	char			*newligne;
	ssize_t			ride;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

}*/

int main (void)
{
	char buff[5];
	int fd;
	int i;
	char *filename;
	int char_read;
	ssize_t lire;

	filename = "file.txt";
	fd = open(filename, O_RDONLY);
	
	while((char_read = read(fd, buff,5)))
	{
		buff[char_read] = '\0';
		printf("buff\t%d = :%s:\n",i,buff);
		i++;
	}
}
