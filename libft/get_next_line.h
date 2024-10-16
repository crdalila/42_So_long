/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:29 by dalcabre          #+#    #+#             */
/*   Updated: 2024/09/27 12:12:01 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 3
# endif //buffer_size

char	*get_next_line(int fd);
char	*read_document(char *buffer, char *saved, int fd);
char	*prepare_new_line(char *saved);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s1);
char	*ft_strchr_gnl(char *s, char c);
void	ft_memcpy_gnl(char *dest, char *src, size_t n);

# endif //librería