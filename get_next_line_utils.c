/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:58:31 by atardif           #+#    #+#             */
/*   Updated: 2022/12/01 12:21:12 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	if (len > ft_strlen(s) - 1 - start)
		len = (ft_strlen(s) - start);
	else if (start > ft_strlen(s) - 1)
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && y < len)
		{
			dest[y] = s[i];
			y++;
		}
		i++;
	}
	dest[y] = 0;
	return (dest);
}

int	ft_reschr(char *res)
{
	size_t	i;
	char	c;

	i = 0;
	c = 10;
	if (!res)
		return (-1);
	while (res[i])
	{
		if (res[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	while (src[i] && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*dest;
	int		i;
	int		y;

	i = 0;
	y = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = 0;
	return (dest);
}
