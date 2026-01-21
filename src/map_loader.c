/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhensel <flhensel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:29:49 by flhensel          #+#    #+#             */
/*   Updated: 2026/01/21 18:10:13 by flhensel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_map_lines(char *filename, int *height, int *width)
{
	int		fd;
	char	*line;

	*height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	line = get_next_line(fd);
	while (line)
	{
		if (*height == 0)
			*width = ft_strlen(line) - 1;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static char	**read_map_lines(char *filename, int height)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		error_exit("Failed to allocate memory for map");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Failed to open map file");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**load_map(char *filename, int *height, int *width)
{
	char	**map;

	count_map_lines(filename, height, width);
	map = read_map_lines(filename, *height);
	return (map);
}
