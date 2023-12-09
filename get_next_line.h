/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:37 by jroulet           #+#    #+#             */
/*   Updated: 2023/12/09 20:51:26 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

typedef struct s_node{
	char 			node_buff[BUFFER_SIZE + 1];
	struct s_node	*next;
}t_node;

void ft_onfreetoutca(t_node **head, t_node *new_node, char *buff);
int ft_length_node(t_node *head);
int ft_found_newligne(t_node *head);
t_node *ft_find_last_node(t_node *head);
void	ft_node_insert_to_end(t_node **head, char *buff);
void	ft_create_list(t_node **list, int fd);
void ft_copy_node(t_node *head, char *str);
char *ft_create_line(t_node *head);
void ft_cleaning(t_node **head);
char *get_next_line(int fd);


#endif
