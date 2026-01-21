/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:09:01 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 18:03:38 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectables;
	int		moves;
	int		exit_open;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collectable_img;
	void	*exit_img;
}	t_game;

typedef struct s_map_check
{
	int	player_count;
	int	exit_count;
	int	collectable_count;
	int	player_x;
	int	player_y;
}	t_map_check;

typedef struct s_flood
{
	int	**vis;
	int	x;
	int	y;
	int	*got_c;
	int	*got_e;
}	t_flood;

/* so_long_utils.c */
void	error_exit(char *message);
void	check_ber_extension(char *filename);
void	free_map(char **map);
int		close_game(t_game *game);

/* map_validate.c */
void	validate_map(char **map, int h, int w);

/* map_borders.c */
int		is_valid_char(char c);
void	check_borders(char **map, int h, int w);

/* map_pathfinding.c */
void	validate_path(char **map, int h, int w, t_map_check *check);

/* map_loader.c */
char	**load_map(char *filename, int *height, int *width);

/* game_init.c */
void	init_game(t_game *game);
void	load_textures(t_game *game);
void	destroy_images(t_game *game);

/* game_render.c */
void	render_map(t_game *game);

/* player_movement.c */
void	move_player(t_game *game, int dx, int dy);
int		handle_key(int keycode, t_game *game);

#endif