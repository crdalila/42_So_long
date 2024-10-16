/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:21:20 by dalcabre          #+#    #+#             */
/*   Updated: 2024/02/12 13:58:21 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define BASEHEXAMAYUS "0123456789ABCDEF"
# define BASEHEXAMINUS "0123456789abcdef"

int	ft_printf(const char *str, ...);
int	ft_printf_char(char c);
int	ft_printf_str(const char *str);
int	ft_printf_number(long n);
int	ft_printf_unsigned(unsigned long n);
int	ft_printf_hexa(unsigned long n, char *base);
int	ft_printf_pointer(unsigned long int n);

#endif