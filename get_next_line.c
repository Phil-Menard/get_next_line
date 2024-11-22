/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:30 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/22 16:28:44 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	size_t		i;

	if (buffer != NULL)
		free(buffer);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		printf("probleme allocation memoire!\n");
		return (NULL);
	}
	bytes_read = read(fd, buffer, 1); 
	printf("Contenu de buffer : %s\n", buffer);
	if (bytes_read == -1)
	{
		printf("Erreur lors de la lecture.\n");
		return(NULL);
	}
	i = 0;
	buffer[bytes_read] = '\0';
	while (buffer[i] != '\n' && buffer[i])
		i++;
	buffer[i + 1]= '\0';
	return (buffer);
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
	if (file_content != NULL)
	{
		printf("Contenu du fichier : \n%s", file_content);
		while (file_content)
		{
			file_content = get_next_line(fd);
			printf("Contenu du fichier : %s", file_content);
		}
		free(file_content);
		close(fd);
	}
	return (0);
}

// read() => ssize_t read(int fd, void *buf, size_t count);