/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:30 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/23 19:57:56 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	ssize_t		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	result = get_next_string(bytes_read, buffer);
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
		file_content = get_next_line(fd);
		printf("%s", file_content);
	}
	printf("\n");
	close(fd);
	free(file_content);
	return (0);
}

// read() => ssize_t read(int fd, void *buf, size_t count);