/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:13:23 by atardif           #+#    #+#             */
/*   Updated: 2022/12/04 10:58:51 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fillres(char *res, char *buffer)
{
	char	*temp;

	if (!res && buffer[0] != 0)
	{
		res = malloc(sizeof(char));
		res[0] = 0;
	}
	temp = ft_strjoinmod(res, buffer);
	free(res);
	return (temp);
}

char	*ft_filline(char *res)
{
	int		set;
	char	*line;

	set = ft_reschr(res);
	if (set == -1)
		set = ft_strlen(res) - 1;
	line = malloc(sizeof(char) * (set + 2));
	if (!line)
		return (NULL);
	ft_strlcpymod(line, res, (set + 2));
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
	temp = ft_substrmod(res, (set + 1), (ft_strlen(res) - set - 1));
	free(res);
	return (temp);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(res);
			res = NULL;
			break ;
		}
		buffer[size] = 0;
		res = ft_fillres(res, buffer);
		if (ft_reschr(res) >= 0)
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read(fd, res);
	if (!res)
		return (NULL);
	line = ft_filline(res);
	if (!line)
		return (NULL);
	res = ft_resetres(res);
	return (line);
}
