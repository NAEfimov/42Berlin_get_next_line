/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:44:12 by nefimov           #+#    #+#             */
/*   Updated: 2024/12/04 13:57:27 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>    // For open() and O_* constants
#include <unistd.h>   // For read(), write(), close(), and lseek()
#include <stdio.h>    // For perror()
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
