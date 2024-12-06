/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:13:23 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/06 13:00:52 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
	{
		len++;
	}
	return (len);
}

char	*ft_strljoin(char *s1, char *s2, size_t size)
{
	char	*fd;
	char	*str;
	char	*s1_to_free;

	s1_to_free = s1;
	fd = (char *) malloc((ft_strlen(s1) + size + 1) * sizeof(char));
	if (fd == NULL)
		return (NULL);
	str = fd;
	while (*s1)
	{
		*str++ = *s1;
		s1++;
	}
	while (size > 0)
	{
		*str++ = *s2;
		*s2 = '\0';
		s2++;
		size--;
	}
	*str = '\0';
	free(s1_to_free);
	return (fd);
}

char	*alloc_zero(void)
{
	char	*p;

	p = (char *) malloc(1);
	if (p == NULL)
		return (NULL);
	*p = '\0';
	return (p);
}

int	check_init_buff(char *buff, ssize_t	fd)
{
	ssize_t	i;
	ssize_t	rd;

	if (fd < 0)
		return (-1);
	i = 0;
	while (buff[i] == 0 && i < BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
			return (-1);
		i = 0;
	}
	return (i);
}

char	*read_new_line(ssize_t	i, char *buff, ssize_t	fd)
{
	char	*str;
	ssize_t	start;
	ssize_t	rd;

	start = i;
	str = alloc_zero();
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (++i == BUFFER_SIZE)
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
