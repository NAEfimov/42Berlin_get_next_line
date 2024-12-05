/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:13:23 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/05 10:01:06 by nefimov          ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str != NULL)
	{
		i = 0;
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fd;
	char	*str;

	fd = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (fd == NULL)
		return (NULL);
	str = fd;
	while (*s1)
	{
		*str++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*str++ = *s2;
		s2++;
	}
	*str = '\0';
	return (fd);
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
		*s2 = 0;
		s2++;
		size--;
	}
	*str = '\0';
	free(s1_to_free);
	return (fd);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		cplen;
	size_t		slen;
	char		*fd;

	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	cplen = 0;
	while (s[start + cplen] && len > 0)
	{
		cplen++;
		len--;
	}
	fd = (char *) malloc((cplen + 1) * sizeof(char));
	if (fd == NULL)
		return (NULL);
	i = 0;
	while (i < cplen)
	{
		fd[i] = s[start + i];
		i++;
	}
	fd[i] = '\0';
	return (fd);
}
void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *p;
		char    *char_p;
		size_t  i;

        if ((size > 0) && (nmemb > SIZE_MAX / size))
                return (NULL);
        p = malloc(nmemb * size);
        if (p == NULL)
                return (NULL);
        i = 0;
        char_p = (char *)p;
        while (i <= nmemb)
        {
                char_p[i] = 0;
                i++;
        }
        return (p);
}
