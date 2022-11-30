/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:13:23 by atardif           #+#    #+#             */
/*   Updated: 2022/11/30 18:50:21 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*ft_fillres(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*ft_filline(char *res)
{
	int		set;
	char	*line;

	set = ft_reschr(res);
	line = malloc(sizeof(char) * (set + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, res, (set + 2));
	return (line);
}

char	*ft_resetres(char *res)
{
	char	*temp;
	int		set;

	set = ft_reschr(res);
	if (set == -1)
	{
		free(res);
		return (NULL);
	}	
	temp = ft_substr(res, (set + 1), (ft_strlen(res) - set - 1));
	free(res);
	return (temp);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		size;

	if (!res)
	{
		res = malloc(sizeof(char));
		res[0] = 0;
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size >= 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		res = ft_fillres(res, buffer);
		if (ft_reschr(res) >= 0 || size == 0)
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res = NULL;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read(fd, res);
	line = ft_filline(res);
	res = ft_resetres(res);
	return (line);
}
