/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:35:26 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:40:42 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	len_s;
	char	*sub;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (n > len_s - start)
		n = len_s - start;
	s = s + start;
	sub = malloc (n + 1);
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s, n);
	sub[n] = '\0';
	return (sub);
}

/*#include <stdio.h>
int	main(void)
{
	const char *s = "There are two and the one in the middle falls";
	const char *sub = ft_substr(s, 4, 12);
	printf("%s", sub);
	free(sub);
	return (0);
}*/