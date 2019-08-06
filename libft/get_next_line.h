/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:47:05 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/27 19:32:57 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include "fcntl.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 32

typedef struct		s_line
{
	char			*str;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
int					reading(int fd, char **line, t_line **head);
void				get_tail(const int fd, char *buf, t_line **head);
int					len(char *s, int c);

#endif
