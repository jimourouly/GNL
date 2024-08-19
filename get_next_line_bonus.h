/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/19 18:20:33 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
//ulimit -aS
# define MAX_FD 256
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

typedef struct s_list{
	char			*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);

t_list	*ft_find_last_node(t_list *head);
int		ft_new_line(t_list *head);
void	create_line(char **line, t_list *node);
void	free_node(t_list *node);
int		ft_strlen(const char *str);
void	read_add_to_node(int fd, t_list **node);
void	add_to_node(t_list **node, char *buffer, int byteread);
void	read_line(t_list *node, char **line);
int		clean_node(t_list **node, int i, int j);

#endif
