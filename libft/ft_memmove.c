/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:56:52 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:51:17 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	if (dest > src && dest < src + n)
	{
		while (i < n)
		{
			((char *)dest)[n - 1 - i] = ((char *)src)[n - 1 - i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>
int	main(void)
{
	char *src = "Hi there, little friend";
	char dest[20];
	ft_memmove(dest, src, 7);
	printf("Source: %s\n", src);
	printf("Dest: %s\n", dest);
	return (0);
}*/