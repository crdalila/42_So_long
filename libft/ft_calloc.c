/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:00:16 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/12 14:05:42 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*array;
	size_t	total_size;
	size_t	i;

	i = 0;
	total_size = (num_elements * element_size);
	array = malloc(total_size);
	if (array == NULL)
		return (NULL);
	while (i < total_size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

/*int	main(void)
{
	ft_calloc(5, 10);
	free()
	return (0);
}*/