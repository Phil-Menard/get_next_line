/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:46:08 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/25 12:24:15 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fill_tmp(char *str, char *tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
		i++;
	while (*str)
	{
		tmp[i] = *str;
		if (tmp[i] == '\n')
		{
			tmp[i + 1] = '\0';
			return (tmp);
		}
		i++;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_putstr(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_realloc(char *tmp)
{
	char	*ptr;
	size_t	len_tmp;

	len_tmp = ft_strlen(tmp);
	ptr = malloc((len_tmp + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_putstr(tmp, ptr);
	if (tmp)
		free(tmp);
	tmp = NULL;
	tmp = malloc((len_tmp + BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	ptr = ft_putstr(ptr, tmp);
	if (ptr)
		free(ptr);
	return (tmp);
}

char	*get_buffer(char *buffer, char *str, ssize_t bytes_read, int fd)
{
	char	*tmp;
	char	*del;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	str = ft_putstr(buffer, str);
	while (bytes_read > 0)
	{
		tmp = fill_tmp(str, tmp);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			return (tmp);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_strlen(str) < BUFFER_SIZE)
		{
			del = str;
			free(del);
			str = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (str == NULL)
				return (NULL);
		}
		str = ft_putstr(buffer, str);
		tmp = ft_realloc(tmp);
	}
	return (tmp);
}

char	*get_next_string(ssize_t bytes_read, char *buffer, int fd)
{
	static char	*str;

	if (str == NULL)
	{
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	if (bytes_read == -1)
		return (NULL);
	else if (bytes_read == 0)
	{
		if (str)
			free(str);
		return (NULL);
	}
	else
	{
		return (get_buffer(buffer, str, bytes_read, fd));
	}
}
