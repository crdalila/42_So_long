/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:20:16 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:51 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s2_len;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	s2_len = end - start;
	s2 = (char *)malloc(s2_len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, (s2_len + 1));
	s2[s2_len] = '\0';
	return (s2);
}

/*int main(void)
{
    char const *s1 = "Hi, I'm Edu";
    char const *set = "Hi, I";
    char const *result = ft_strtrim(s1, set);
    printf("%s", result);
    free((void *) result);
    return (0);
}*/