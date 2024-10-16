/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:35:45 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:51:48 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_lenght(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_duplicate(char *src, int lenght, char *dup)
{
	int	j;

	j = 0;
	while (j < lenght)
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

char	*ft_strdup(char *src)
{
	int		lenght;
	char	*dup;

	lenght = str_lenght(src);
	dup = (char *)malloc((lenght + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_duplicate(src, lenght, dup);
	return (dup);
}

/*#include <stdio.h>
int	main(void)
{
	char *str = "Ty nicoooo";
	char *duplicate = ft_strdup(str);
	printf("%s", duplicate);
	free(duplicate);
	return(0);
}*/