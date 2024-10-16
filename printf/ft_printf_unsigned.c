/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:04:53 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/08 11:18:40 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned long n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_printf_number(n / 10);
	ft_printf_char((n % 10) + '0');
	length++;
	return (length);
}
