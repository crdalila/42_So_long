/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:03:04 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/11 10:11:41 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = ptr;
	while (i < n)
	{
		*p = (unsigned char)value;
		p++;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[20];
// 	ft_memset(str, 'A', 10);
// 	printf("%s\n", str);
// 	return (0);
// }
