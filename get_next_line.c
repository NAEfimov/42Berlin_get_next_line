/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:11:59 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/04 17:13:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*str;
	char			*str1;
	char			*str2;
	static ssize_t	i;
	static ssize_t	start;
	ssize_t			rd;
	
	if (fd < 0)
		return (NULL);
	str = "";
	if (i == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1 || rd == 0)
		{
			return (NULL);
			// free str;
		}
		start = 0;
	}
	while (i <= rd)
	{
		if (buff[i] == '\0')
		{
			str1 = ft_substr(buff, start, (i - start + 1));
			str2 = ft_strjoin(str, str1);
			str = str2;
			i = 0;
			start = 0;
			return (str); 
		}
		if (buff[i] == '\n')
		{
			str1 = ft_substr(buff, start, (i - start + 1));
			str2 = ft_strjoin(str, str1);
			str = str2;
			start = ++i;
			return (str);
		}
		if (i == rd)
		{
			str1 = ft_substr(buff, start, (i - start + 1));
			str2 = ft_strjoin(str, str1);
			str = str2;
			rd = read(fd, buff, BUFFER_SIZE);
			if (rd == -1 || rd == 0)
			{
				return (NULL);
				// free str;
			}
			i = 0;
			start = 0;
		}
		i++;
	}
}
