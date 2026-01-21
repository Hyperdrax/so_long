/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:23:36 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/17 10:25:27 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;
	unsigned char	uc;

	s = (unsigned char *) str;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s[i] == uc)
			return ((void *) &s[i]);
		i++;
	}
	return (0);
}
