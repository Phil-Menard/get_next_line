/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:58:44 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/26 11:53:29 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50000000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_strchr(char *src, int c);
char	*ft_putstr(char *src, char *dest, int i);
char	*ft_putline(char *src, char *dest);
char	*ft_realloc(char *str, char *buffer);

#endif
