/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:55:12 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:50:59 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	c2;

	i = 0;
	s2 = (unsigned char *)s;
	c2 = c;
	while (i < n)
	{
		if ((s2[i]) == (c2))
			return (s2 + i);
		else
			i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char *str = "Hi there, little friend";
	printf("%s\n", ft_memchr(str, 'a', 4));
	return (0);
}*/