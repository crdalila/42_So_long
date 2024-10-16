/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:33:24 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/12 10:27:34 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	beforeint;

	i = 0;
	beforeint = (char)c;
	while (s[i] || beforeint == '\0')
	{
		if (s[i] == beforeint)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
