/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:07:43 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/19 18:47:30 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

char		*get_next_line(int fd);

typedef struct s_list_char{
	char				*cont;
	struct s_list_char	*next;
}				t_list_char;

char		*get_next_line(int fd);
t_list_char	*ft_find_last_node(t_list_char *head);
int			ft_new_line(t_list_char *head);
void		create_line(char **line, t_list_char *node);
void		free_node(t_list_char *node);
int			ft_strlen_int(const char *str);
void		read_add_to_node(int fd, t_list_char **node);
void		add_to_node(t_list_char **node, char *buffer, int byteread);
void		read_line(t_list_char *node, char **line);
int			clean_node(t_list_char **node, int i, int j);
bool		ft_isonstr(const char *str, int ch);

#endif
