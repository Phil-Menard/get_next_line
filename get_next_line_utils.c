/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:46:08 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/25 18:19:36 by pmenard          ###   ########.fr       */
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

char	*fill_tmp(char **str, char *tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	while (**str)
	{
		tmp[i] = **str;
		if (tmp[i] == '\n')
		{
			tmp[i + 1] = '\0';
			(*str)++;
			return (tmp);
		}
		i++;
		(*str)++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_putstr(char *src, char *dest)
{
	size_t	i;

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
	tmp = malloc((len_tmp + BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp = ft_putstr(ptr, tmp);
	if (ptr)
		free(ptr);
	return (tmp);
}
