/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:47:48 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 18:06:44 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(char **map, int h, int w)
{
	int	y;

	y = 0;
	while (y < h)
	{
		if ((int)ft_strlen(map[y]) != w)
			error_exit("Map must be rectangular");
		y++;
	}
}

static void	update_check(char c, int x, int y, t_map_check *check)
{
	if (c == 'P')
	{
		check->player_count++;
		check->player_x = x;
		check->player_y = y;
	}
	if (c == 'E')
		check->exit_count++;
	if (c == 'C')
		check->collectable_count++;
}

static void	count_elements(char **map, int h, int w, t_map_check *check)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (!is_valid_char(map[y][x]))
				error_exit("Map contains invalid character");
			update_check(map[y][x], x, y, check);
			x++;
		}
		y++;
	}
}

static void	verify_element_counts(t_map_check *check)
{
	if (check->player_count != 1)
		error_exit("Map needs exactly 1 player");
	if (check->exit_count != 1)
		error_exit("Map needs exactly 1 exit");
	if (check->collectable_count < 1)
		error_exit("Map needs at least 1 collectable");
}

void	validate_map(char **map, int h, int w)
{
	t_map_check	check;

	if (!map || h <= 0 || w <= 0)
		error_exit("Invalid map dimensions");
	check.player_count = 0;
	check.exit_count = 0;
	check.collectable_count = 0;
	check_rectangular(map, h, w);
	count_elements(map, h, w, &check);
	verify_element_counts(&check);
	check_borders(map, h, w);
	validate_path(map, h, w, &check);
}
