/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:46:08 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/23 20:09:02 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer(char *buffer, char *str, ssize_t bytes_read)
{
	ssize_t	i;

	i = 0;
	while (i < bytes_read)
	{
		str[i] = buffer[i];
		i++;
	}
	if (i < bytes_read && buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_string(ssize_t bytes_read, char *buffer)
{
	static char	*str;

	if (str == NULL)
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (bytes_read == -1)
		return(NULL);
	else if (bytes_read == 0)
	{
		free(str);
		return (NULL);
	}
	else
	{
		return (get_buffer(buffer, str, bytes_read));
	}
}
