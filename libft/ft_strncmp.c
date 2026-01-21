/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:17:53 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/31 12:04:35 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *w, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i] && w[i])
	{
		if (s[i] != w[i])
			return ((unsigned char)s[i] - (unsigned char)w[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s[i] - (unsigned char)w[i]);
	return (0);
}
