/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:08:25 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/13 13:17:26 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(long n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		ft_printf_char('-');
		n = -n;
		length++;
	}
	if (n >= 10)
		length += ft_printf_number(n / 10);
	ft_printf_char((n % 10) + '0');
	length++;
	return (length);
}
