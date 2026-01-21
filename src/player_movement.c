/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:25:32 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 17:46:00 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, char target)
{
	if (target == '1')
		return (0);
	if (target == 'E' && game->collectables > 0)
		return (0);
	return (1);
}

static void	update_position(t_game *game, int nx, int ny)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = nx;
	game->player_y = ny;
	game->map[ny][nx] = 'P';
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

static void	check_win(t_game *game, char target)
{
	if (target == 'E' && game->collectables == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		close_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	target;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	target = game->map[ny][nx];
	if (!can_move(game, target))
		return ;
	if (target == 'C')
		game->collectables--;
	update_position(game, nx, ny);
	check_win(game, target);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119 || keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}
