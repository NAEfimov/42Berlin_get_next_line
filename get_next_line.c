/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:11:59 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/06 11:41:52 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*str;
	ssize_t	i;
	ssize_t	start;
	ssize_t	rd;
	
	if (fd < 0)
		return (NULL);
	str = ft_calloc(1, 1);
	
	i = 0;
	while (buff[i] == 0 && i < BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			free(str);
			return (NULL);
		}
		i = 0;
	}
	start = i;
	
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		i++;
		if (i == BUFFER_SIZE)
		{
		str = ft_strljoin(str, &buff[start], BUFFER_SIZE - start);
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			if (*str)
				return (str);
			free(str);			
			return (NULL);
		}
		i = 0;
		start = i;
		}
	}
	str = ft_strljoin(str, &buff[start], (i - start + 1));
	return (str);
}
