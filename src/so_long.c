/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:09:08 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 17:36:07 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game	game;
	int		height;
	int		width;

	if (ac != 2)
		error_exit("Usage: ./so_long <map_file.ber>");
	check_ber_extension(av[1]);
	game.map = load_map(av[1], &height, &width);
	validate_map(game.map, height, width);
	game.map_height = height;
	game.map_width = width;
	init_game(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
