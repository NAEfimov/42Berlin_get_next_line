/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:12:24 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/06 12:58:38 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		check_init_buff(char *buff, ssize_t	fd);
char	*read_new_line(ssize_t	i, char *buff, ssize_t	fd);

size_t	ft_strlen(const char *s);
char	*ft_strljoin(char *s1, char *s2, size_t size);
char	*alloc_zero(void);

#endif