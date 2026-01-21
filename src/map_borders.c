/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:51:30 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 18:08:22 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static void	check_top_bottom_borders(char **map, int h, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		if (map[0][i] != '1' || map[h - 1][i] != '1')
			error_exit("Map border must be walls");
		i++;
	}
}

static void	check_left_right_borders(char **map, int h, int w)
{
	int	i;

	i = 0;
	while (i < h)
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			error_exit("Map border must be walls");
		i++;
	}
}

void	check_borders(char **map, int h, int w)
{
	check_top_bottom_borders(map, h, w);
	check_left_right_borders(map, h, w);
}
