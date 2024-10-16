/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:54:47 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/12 14:26:14 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(unsigned long int n)
{
	ft_printf_str("0x");
	return (ft_printf_hexa(n, BASEHEXAMINUS) + 2);
}
