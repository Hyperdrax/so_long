/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:57:56 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 18:00:24 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int h, int w, t_flood *flood)
{
	if (flood->y < 0 || flood->y >= h || flood->x < 0 || flood->x >= w)
		return ;
	if (map[flood->y][flood->x] == '1' || flood->vis[flood->y][flood->x])
		return ;
	flood->vis[flood->y][flood->x] = 1;
	if (map[flood->y][flood->x] == 'C')
		(*flood->got_c)++;
	if (map[flood->y][flood->x] == 'E')
		*flood->got_e = 1;
	flood->y++;
	flood_fill(map, h, w, flood);
	flood->y -= 2;
	flood_fill(map, h, w, flood);
	flood->y++;
	flood->x++;
	flood_fill(map, h, w, flood);
	flood->x -= 2;
	flood_fill(map, h, w, flood);
	flood->x++;
}

static int	**allocate_visited(int h, int w)
{
	int	**vis;
	int	y;

	vis = ft_calloc(h, sizeof(int *));
	if (!vis)
		error_exit("Allocation failed");
	y = 0;
	while (y < h)
	{
		vis[y] = ft_calloc(w, sizeof(int));
		if (!vis[y])
			error_exit("Allocation failed");
		y++;
	}
	return (vis);
}

static void	free_visited(int **vis, int h)
{
	int	y;

	y = 0;
	while (y < h)
		free(vis[y++]);
	free(vis);
}

void	validate_path(char **map, int h, int w, t_map_check *check)
{
	t_flood	flood;
	int		got_c;
	int		got_e;

	flood.vis = allocate_visited(h, w);
	got_c = 0;
	got_e = 0;
	flood.got_c = &got_c;
	flood.got_e = &got_e;
	flood.x = check->player_x;
	flood.y = check->player_y;
	flood_fill(map, h, w, &flood);
	free_visited(flood.vis, h);
	if (got_c != check->collectable_count || !got_e)
		error_exit("Not all collectables/exit reachable");
}
