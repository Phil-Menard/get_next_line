/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:30 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/22 12:33:03 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	//malloc buffer avec quoi?
	return (NULL);
}

int	main(void)
{
	

	return (0);
}

/*
pas le droit d'utiliser open(), donc je dois utiliser read()
mais je peux utiliser open() dans le main pour les tests

proto de read() => ssize_t read(int fd, void *buf, size_t count);

COMMENCER AVEC ENTREE CLAVIER?? => utilisation de write ! 
=> read(0) && write(1)

*/