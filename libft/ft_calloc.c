/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:38:24 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/17 10:38:39 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	char	*char_str;
	void	*allocated_memory;

	total_size = nitems * size;
	if (nitems != 0 && total_size / nitems != size)
	{
		return (NULL);
	}
	allocated_memory = malloc(total_size);
	if (allocated_memory != NULL)
	{
		char_str = (char *)allocated_memory;
		while (total_size--)
			*char_str++ = (char)0;
	}
	return (allocated_memory);
}
