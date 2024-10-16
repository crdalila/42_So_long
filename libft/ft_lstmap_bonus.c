/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:15:46 by dalcabre          #+#    #+#             */
/*   Updated: 2024/01/25 14:06:27 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*count_node;
	void	*content;

	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		count_node = ft_lstnew(content);
		if (!count_node)
		{
			free(content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, count_node);
		lst = lst->next;
	}
	return (new_lst);
}
