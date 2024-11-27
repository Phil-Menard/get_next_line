/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:03:57 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/27 14:04:23 by pmenard          ###   ########.fr       */
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

int	ft_strchr(char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_putline(char *src, char *dest)
{
	int	i;

	i = 0;
	if (src[0] == '\0')
		return (NULL);
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_putstr(char *src, char *dest, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_realloc(char *str, char *buffer)
{
	size_t	len_str;
	char	*new_str;

	len_str = ft_strlen(str);
	new_str = malloc((len_str + ft_strlen(buffer) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (str)
	{
		new_str = ft_putstr(str, new_str, 0);
		free(str);
	}
	return (new_str);
}
