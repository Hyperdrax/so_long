/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:09:08 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 14:21:19 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_exit(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

static void check_ber_extension(char *filename)
{
	size_t len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		error_exit("Map file must have .ber extension");
}

static void free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void destroy_images(t_game *game)
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

char **load_map(char *filename, int *height, int *width)
{
	int fd;
	char *line;
	char **map;
	int i;

	*height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	while ((line = get_next_line(fd)))
	{
		if (*height == 0)
			 *width = ft_strlen(line) - 1;
		(*height)++;
		free(line);
	}
	close(fd);

	map = malloc(sizeof(char *) * (*height + 1));
	if (!map)
		error_exit("Failed to allocate memory for map");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);

	return (map);
}

void load_textures(t_game *game)
{
	int width;
	int height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &width, &height);
	if (!game->wall_img)
		error_exit("Failed to load wall texture");

	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm", &width, &height);
	if (!game->floor_img)
		error_exit("Failed to load floor texture");

	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &width, &height);
	if (!game->player_img)
		error_exit("Failed to load player texture");

	game->collectable_img = mlx_xpm_file_to_image(game->mlx, "./textures/collectable.xpm", &width, &height);
	if (!game->collectable_img)
		error_exit("Failed to load collectable texture");

	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &width, &height);
	if (!game->exit_img)
		error_exit("Failed to load exit texture");
}

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to initialize MLX");
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		error_exit("Failed to create window");
	game->moves = 0;
	game->collectables = 0;
	game->exit_open = 0;

	int y = 0;
	while (y < game->map_height)
	{
		int x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'C')
				game->collectables++;
			x++;
		}
		y++;
	}
	load_textures(game);
}

void render_map(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->floor_img, 
                x * TILE_SIZE, y * TILE_SIZE);
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_img,
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectable_img,
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
                    x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void move_player(t_game *game, int dx, int dy)
{
	int     nx;
	int     ny;
	char    target;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	target = game->map[ny][nx];
	if (target == '1')
		return ;
	if (target == 'E' && game->collectables > 0)
		return ;
	if (target == 'C')
		game->collectables--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = nx;
	game->player_y = ny;
	game->map[ny][nx] = 'P';
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	if (target == 'E' && game->collectables == 0)
	{
		ft_putstr_fd("You win!\n", 1);
		close_game(game);
	}
	render_map(game);
}

int handle_key(int keycode, t_game *game)
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

int close_game(t_game *game)
{
	free_map(game->map);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int main(int ac, char *av[])
{
	t_game game;
	int height;
	int width;

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
