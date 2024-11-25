/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:30 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/25 18:48:45 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_buffer(char *buffer, char **str, ssize_t bytes_read, int fd)
{
	char		*tmp;
	static char	*ptr;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	if (ptr == NULL)
		ptr = *str;
	if (ft_strlen(*str) < BUFFER_SIZE)
	{
		tmp = fill_tmp(str, tmp);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			return (tmp);
		tmp = ft_realloc(tmp);
		*str = ptr;
		*str = ft_putstr(buffer, *str);
	}
	while (bytes_read > 0)
	{
		tmp = fill_tmp(str, tmp);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			return (tmp);
		tmp = ft_realloc(tmp);
		if (**str == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			*str = ptr;
			*str = ft_putstr(buffer, *str);
		}
	}
	return (tmp);
}

char	*get_next_string(ssize_t bytes_read, char *buffer, int fd)
{
	static char	*str;
	static char	*ptr;

	if (str == NULL)
	{
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		ptr = str;
		str[0] = '\0';
	}
	if (bytes_read == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	else
	{
		if (ft_strlen(str) == BUFFER_SIZE)
			str = ft_putstr(buffer, str);
		if (*str == '\0')
		{
			str = ptr;
			str = ft_putstr(buffer, str);
		}
		return (get_buffer(buffer, &str, bytes_read, fd));
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	ssize_t		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	if (bytes_read == -1)
		return (NULL);
	result = get_next_string(bytes_read, buffer, fd);
	if (buffer)
		free(buffer);
	return (result);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*file_content;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}
	file_content = get_next_line(fd);
	printf("%s", file_content);
	while (file_content != NULL)
	{
		free(file_content);
		file_content = get_next_line(fd);
		printf("%s", file_content);
	}
	if (file_content)
		free(file_content);
	printf("\n");
	close(fd);
	return (0);
}

// read() => ssize_t read(int fd, void *buf, size_t count);