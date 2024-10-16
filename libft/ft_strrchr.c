/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:45:56 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/12 10:57:07 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;
	int		length;

	new_s = (char *)s;
	length = ft_strlen(s);
	while (length != 0)
	{
		if (new_s[length] == (char)c)
			return (new_s + length);
		length--;
	}
	if (new_s[0] == (char)c)
		return (new_s);
	return (NULL);
}
