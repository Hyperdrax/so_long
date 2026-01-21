/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:32:20 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 17:39:27 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectable_img)
		mlx_destroy_image(game->mlx, game->collectable_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	if (!game->wall_img)
		error_exit("Failed to load wall texture");
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &width, &height);
	if (!game->floor_img)
		error_exit("Failed to load floor texture");
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &width, &height);
	if (!game->player_img)
		error_exit("Failed to load player texture");
	game->collectable_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectable.xpm", &width, &height);
	if (!game->collectable_img)
		error_exit("Failed to load collectable texture");
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &width, &height);
	if (!game->exit_img)
		error_exit("Failed to load exit texture");
}

static void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	count_collectables(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collectables++;
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to initialize MLX");
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		error_exit("Failed to create window");
	game->moves = 0;
	game->collectables = 0;
	game->exit_open = 0;
	find_player_position(game);
	count_collectables(game);
	load_textures(game);
}
