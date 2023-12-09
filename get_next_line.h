/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:37 by jroulet           #+#    #+#             */
/*   Updated: 2023/12/09 17:06:50 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stlib.h>
# include <unistd.h>

char *get_next_line(int fd);

typedef struct s_node{
	char 			/*buffersize*/;
	struct s_node	*next;
}t_node;



#endif
