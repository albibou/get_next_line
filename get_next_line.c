/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:13:23 by atardif           #+#    #+#             */
/*   Updated: 2022/11/25 18:25:35 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_fillres(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	return (temp);
}

char	*ft_filline(char *res)
{
	size_t	set;
	char	*line;

	set = ft_reschr(res);
	line = malloc(sizeof(char) * (set + 2));
	ft_strlcpy(line, res, (set + 2));
	return (line);
}


char	*ft_resetres(char *res)
{
	char	*temp;
	int	set;

	set = ft_reschr(res);
	temp = ft_substr(res, (set + 1), (BUFFER_SIZE + 1));
	return (temp);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int	size;

	if (!res)
		res = malloc(sizeof(char));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size >= 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		res = ft_fillres(res, buffer);
		if (ft_reschr(res) >= 0)
			break;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static	char	*res;
	char		*line;

	res = ft_read(fd, res);
	line = ft_filline(res);
	res = ft_resetres(res);
	return (line);
}
