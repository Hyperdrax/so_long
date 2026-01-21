/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:28:54 by flhensel          #+#    #+#             */
/*   Updated: 2025/08/04 15:29:29 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next_item;

	if (!lst)
		return (NULL);
	next_item = lst;
	while (next_item->next != NULL)
		next_item = next_item->next;
	return (next_item);
}
