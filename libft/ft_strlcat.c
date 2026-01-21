/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:50:06 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/31 11:33:26 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (d_len >= size)
		d_len = size;
	if (d_len == size)
		return (size + s_len);
	if (s_len < size - d_len)
	{
		ft_memcpy(dst + d_len, src, s_len + 1);
	}
	else
	{
		ft_memcpy(dst + d_len, src, size - d_len - 1);
		dst[size - 1] = '\0';
	}
	return (d_len + s_len);
}
