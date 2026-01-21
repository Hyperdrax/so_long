/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:57:16 by flhensel          #+#    #+#             */
/*   Updated: 2025/07/22 15:10:48 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*place(int len)
{
	char	*a;

	a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[0] = '0';
	return (a);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	int				i;
	char			*allocated_memory;
	long			nbr;

	nbr = n;
	len = getlen(n);
	allocated_memory = place(len);
	if (!allocated_memory)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		allocated_memory[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	if (n < 0)
		allocated_memory[0] = '-';
	allocated_memory[len] = 0;
	return (allocated_memory);
}
