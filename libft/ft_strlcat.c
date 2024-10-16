/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:16:04 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:06 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (n < dst_len + 1)
		return (n + src_len);
	if (n > dst_len + 1)
	{
		while (src[i] && (dst_len + 1 + i) < n)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
int	main(void)
{
	char const *src = "abcd";
	char dest[20] = "def";
	size_t n = 1;
	size_t result = ft_strlcat(dest, src, n);
	printf("%zu", result);
	return (0);
}*/