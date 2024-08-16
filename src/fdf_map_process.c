/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:18:20 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/13 14:18:35 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_file_init(t_main *file)
{
	file->fd = open(file->file, O_RDONLY);
	if (file->fd < 0)
		p_error("Error opening the file.");
	file->line = get_next_line(file->fd);
	if (!file->line)
		p_error("Error opening the file.");
	file->got_from_file = ft_split(file->line, ' ');
	if (!file->got_from_file)
		p_error("Error opening the file.");
}

void	ft_read_file(t_main *file)
{
	ft_file_init(file);
	file->width = 0;
	file->height = 0;
	while (file->got_from_file[file->width])
	{
		free(file->got_from_file[file->width]);
		file->width++;
	}
	while (file->line)
	{
		free(file->line);
		file->height++;
		file->line = get_next_line(file->fd);
	}
	ft_printf("Columns: %i\nLines: %i\n", file->width, file->height);
	free(file->got_from_file);
	free(file->line);
	close(file->fd);
}

static void	allocate_map(t_main *map)
{
	map->map = malloc(sizeof(int *) * map->width);
	if (!map->map)
		p_error("Error allocating memory.");
}

static void	fill_map(t_main *map, int fd)
{
	char	*line;
	char	**split;

	map->y = -1;
	while (++map->y < map->height)
	{
		map->map[map->y] = malloc(sizeof(int) * map->width);
		if (!map->map[map->y])
			p_error("Error allocating memory.");
		line = get_next_line(fd);
		if (!line)
			p_error("Error getting the line.");
		split = ft_split(line, ' ');
		if (!split)
			p_error("Empty map, please, select a valid one.");
		map->x = -1;
		while (++map->x < map->width)
		{
			map->map[map->y][map->x] = ft_atoi(split[map->x]);
			free(split[map->x]);
		}
		free(map->map[map->y]);
		free(split);
		free(line);
	}
	line = get_next_line(fd);
	free(line);
	free(map->map);
	// int i = -1, j = -1, r = map->width, c = map->height;
	// while (++j < c)
	// {
	//     i = -1;
	//     while (++i < r)
	//         ft_printf("%i ", map->map[j][i]);
	//     ft_printf("\n");
	// }
}

void	ft_parse_map(t_main *file)
{
	int	fd;

	fd = open(file->file, O_RDONLY);
	if (fd < 0)
		p_error("Error opening the file :(");
	allocate_map(file);
	fill_map(file, fd);
	close(fd);
	// free(file->map);
}
