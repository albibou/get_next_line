/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:55:46 by atardif           #+#    #+#             */
/*   Updated: 2022/11/25 15:52:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE

#endif

#include <stddef.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t  ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
int     ft_reschr(char *res);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char    *ft_strdup(char *s);


#endif
