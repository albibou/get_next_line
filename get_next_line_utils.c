/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:58:31 by atardif           #+#    #+#             */
/*   Updated: 2022/12/02 16:32:25 by atardif          ###   ########.fr       */
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

char	*ft_substrmod(char *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	if (len > ft_strlen(s) - 1 - start)
		len = (ft_strlen(s) - start);
	if (start > ft_strlen(s) - 1)
		return (NULL);
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
	c = '\n';
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

void	ft_strlcpymod(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strjoinmod(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
