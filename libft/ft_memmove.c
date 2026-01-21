/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:34:40 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/17 09:47:00 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copyforward(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*d;
	const char	*s;

	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (dst == src || len == 0)
		return (dst);
	if (d < s && d + len > s)
		ft_copyforward(dst, src, len);
	else if (s < d && s + len > d)
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
		ft_copyforward(dst, src, len);
	return (dst);
}
