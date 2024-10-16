/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:34 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:51:59 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

/*#include <stdio.h>
int	main(void)
{
	const char *s1 = "Hi,";
	const char *s2 = " im Edu";
	const char *result = ft_strjoin(s1, s2);
	printf("La nueva string es: %s", result);
	free((void *)result);
	return (0);
}*/