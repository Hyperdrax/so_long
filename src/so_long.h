/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:09:01 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 14:21:21 by flhensel         ###   ########.fr       */
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
    void        *mlx;
    void        *win;
    char        **map;
    int         map_width;
    int         map_height;

    int         player_x;
    int         player_y;

    int         collectables;
    int         moves;
    int         exit_open;

    void        *wall_img;
    void        *floor_img;
    void        *player_img;
    void        *collectable_img;
    void        *exit_img;
} t_game;

void    error_exit(char *message);
void    validate_map(char **map, int h, int w);
char    **load_map(char *filename, int *height, int *width);
void    load_textures(t_game *game);
void    init_game(t_game *game);
void    render_map(t_game *game);
int     close_game(t_game *game);
int     handle_key(int keycode, t_game *game);
void    move_player(t_game *game, int dx, int dy);

#endif