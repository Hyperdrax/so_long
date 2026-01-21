/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:37:35 by flhensel          #+#    #+#             */
/*   Updated: 2025/08/14 09:49:56 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_list;
	void	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = f(lst->content);
	f_list = ft_lstnew(new);
	if (!f_list)
	{
		if (del && new)
			del(new);
		ft_lstclear(&f_list, del);
		return (NULL);
	}
	f_list->next = ft_lstmap(lst->next, f, del);
	return (f_list);
}
