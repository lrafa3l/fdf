/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:58:59 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/05 14:52:07 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_atoh(char *matrix)
{
	char	c;
	int		check;
	int		hex;

	hex = 0;
	check = 0;
	while (matrix[check] != ',' && matrix[check + 1] != '\0')
		check++;
	if (matrix[check + 1] == '\0')
		return (0xFF6666);
	check += 3;
	while (matrix[check] != '\0')
	{
		c = matrix[check++];
		hex *= 16;
		if (c >= '0' && c <= '9')
			hex += c - '0';
		else if (c >= 'A' && c <= 'F')
			hex += c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			hex += c - 'a' + 10;
		else
			return (0xFF6666);
	}
	return (hex);
}

t_map_info	**ft_get_info(char **matrix, t_main *fdf, int j)
{
	t_map_info	**data;
	int			i;

	fdf->map->max_x = ft_verif_parse_x(matrix, fdf);
	data = (t_map_info **)malloc(sizeof(t_map_info *) * (fdf->map->max_x + 1));
	if (!data)
		ft_print_error(fdf, "Malloc error");
	ft_data_init(data, fdf);
	i = -1;
	while (matrix[++i])
	{
		data[i] = (t_map_info *)malloc(sizeof(t_map_info));
		if (!data[i])
			ft_print_error(fdf, "Malloc error");
		data[i]->x = i;
		data[i]->y = j;
		data[i]->value = ft_atoi(matrix[i]);
		data[i]->color = ft_atoh(matrix[i]);
		ft_max_z(fdf, data[i]->value);
		free(matrix[i]);
	}
	data[i] = NULL;
	free(matrix);
	return (data);
}

void	ft_file_to_map(t_main *fdf, char **matrix)
{
	int	i;

	fdf->map->max_y = 0;
	fdf->map->max_x = 0;
	fdf->map->max_z = -2147483648;
	while (matrix[fdf->map->max_y])
		fdf->map->max_y++;
	fdf->map->map_data = (t_map_info ***)malloc(sizeof(t_map_info **)
			* (fdf->map->max_y + 1));
	if (!fdf->map->map_data)
		ft_mlx_exit(fdf);
	i = -1;
	while (++i < fdf->map->max_y + 1)
		fdf->map->map_data[i] = NULL;
	i = -1;
	while (matrix[++i])
	{
		fdf->map->map_data[i] = ft_get_info(ft_split(matrix[i], 32), fdf, i);
		if (!fdf->map->map_data[i])
			ft_mlx_exit(fdf);
	}
	fdf->map->map_data[i] = NULL;
}

void	ft_check_map(char *map, t_main *fdf)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free(map);
		ft_print_error(fdf, "Map error :(");
	}
	while (map[++i])
	{
		if (map[i] == '\n' && (map[i + 1] == '\n' || map[i + 1] == '\0'))
			break ;
	}
	while (map[i])
		map[i++] = '\0';
}

void	ft_read_map(t_main *fdf, char *file)
{
	char	*file_buff;
	int		file_len;
	int		buff;
	int		fd;

	fd = open(file, O_RDONLY);
	file_len = ft_file_len(file);
	file_buff = (char *)malloc(sizeof(char) * (file_len + 1));
	if (!file_buff)
		ft_mlx_exit(fdf);
	if (!file_buff)
		exit(1);
	buff = read(fd, file_buff, file_len + 1);
	if (!buff)
		ft_mlx_exit(fdf);
	if (!buff)
		exit(1);
	file_buff[buff] = '\0';
	ft_check_map(file_buff, fdf);
	fdf->map->map = ft_split(file_buff, '\n');
	free(file_buff);
	ft_file_to_map(fdf, fdf->map->map);
	close(fd);
}
