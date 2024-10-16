/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:59:48 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/12 14:26:52 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned long n, char *base)
{
	int	length;

	length = 0;
	if (n >= 16)
		length += ft_printf_hexa((n / 16), base);
	ft_printf_char(base[n % 16]);
	length++;
	return (length);
}
