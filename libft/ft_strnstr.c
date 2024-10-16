/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:37:44 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 13:21:15 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s, const char *sub_s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (sub_s[i] == '\0')
		return ((char *)s);
	while (i < n && s[i])
	{
		if (sub_s[0] == s[i])
		{
			j = 0;
			while (sub_s[j] == s[i + j] && (i + j) < n && sub_s[j])
			{
				j++;
			}
			if (ft_strlen(sub_s) == j)
				return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *s = "Hello World! hELLoHello";
// 	const char *sub_s = "ld!";
// 	printf("%s", ft_strnstr(s, sub_s, 21));
// 	return (0);
// }