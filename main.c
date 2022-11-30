/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:57:44 by atardif           #+#    #+#             */
/*   Updated: 2022/11/30 11:25:02 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>



char    *get_next_line(int fd);


int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(0);
	line = get_next_line(fd);
	while (*line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
