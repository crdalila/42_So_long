/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:40:28 by dalcabre          #+#    #+#             */
/*   Updated: 2024/09/27 12:14:02 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	s3 = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!s3)
	{
		free (s3);
		free (s1);
		return (NULL);
	}
	ft_memcpy_gnl(s3, s1, s1_len);
	ft_memcpy_gnl((s3 + s1_len), s2, s2_len);
	s3[s1_len + s2_len] = '\0';
	free(s1);
	return (s3);
}

int		ft_strlen_gnl(char *s1)
{
	size_t	i;

	i = 0;
	if (!s1 || *s1 == '\0')
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, char c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c || c == '\0')
			return (&s[i]);
		i++;
	} 
	return (NULL);
}

void	ft_memcpy_gnl(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}
