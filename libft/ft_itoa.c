/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:21:32 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 17:15:23 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	len_n(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	const char	*digits;

	len = len_n(n);
	digits = "0123456789";
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (n > 0)
			str[--len] = digits[n % 10];
		else
			str[--len] = digits[(n % 10) * -1];
		n = n / 10;
	}
	return (str);
}

/*#include <stdio.h>
int main(void)
{
    int num = -12345;
    char *result = ft_itoa(num);
    printf("Number: %d, String: %s\n", num, result);
    free(result);
    return (0);
}*/