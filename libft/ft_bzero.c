/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:10:55 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/11 10:10:30 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		*p = 0;
		n--;
		p++;
	}
}

/*int	main(void)
{
	char buffer[10];
	int n;
	int i;

	n = 5;
	i = 0;
	ft_bzero(buffer, n);
	while (i < n)
	{
		printf("%d", buffer[i]);
		i++;
	}
	return (0);
}*/
