/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:29:50 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/09 10:15:49 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int argument)
{
	if (argument >= 'A' && argument <= 'Z')
		return (1);
	else if (argument >= 'a' && argument <= 'z' )
		return (1);
	else
		return (0);
}
