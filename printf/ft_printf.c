/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:36:06 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/13 16:51:20 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countcheck(va_list arguments, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count = ft_printf_char(va_arg(arguments, int));
	else if (str == '%')
		count = write(1, "%", 1);
	else if (str == 's')
		count = ft_printf_str(va_arg(arguments, char *));
	else if (str == 'i' || str == 'd')
		count = ft_printf_number(va_arg(arguments, int));
	else if (str == 'u')
		count = ft_printf_unsigned(va_arg(arguments, unsigned int));
	else if (str == 'X')
		count = ft_printf_hexa(va_arg(arguments, unsigned int), BASEHEXAMAYUS);
	else if (str == 'x')
		count = ft_printf_hexa(va_arg(arguments, unsigned int), BASEHEXAMINUS);
	else if (str == 'p')
		count = ft_printf_pointer(va_arg(arguments, unsigned long int));
	else
		count = ft_printf_char(str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arguments, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_countcheck(arguments, str[i + 1]);
			i++;
		}
		else
			count += ft_printf_char(str[i]);
		i++;
	}
	va_end(arguments);
	return (count);
}
