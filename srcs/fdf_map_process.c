/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:58:59 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/25 08:47:02 by lrafael          ###   ########.fr       */
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
		return (0xFFFFFF);
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
			return (0xFFFFFF);
	}
	return (hex);
}

t_z_info	**ft_rdinfo(char **matrix)
{
	t_z_info	**z;
	int			i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	z = (t_z_info **)malloc(sizeof(t_z_info *) * (i + 1));
	if (!z)
		exit(1);
	z[i] = NULL;
	i = -1;
	while (matrix[++i])
	{
		z[i] = (t_z_info *)malloc(sizeof(t_z_info));
		if (!z[i])
			exit(1);
		z[i]->z = ft_atoi(matrix[i]);
		z[i]->color = ft_atoh(matrix[i]);
		free(matrix[i]);
	}
	free(matrix);
	return (z);
}

void	file_to_map(t_main *fdf, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	fdf->map->splited = (t_z_info ***)malloc(sizeof(t_z_info **) * (i + 1));
	if (!fdf->map->splited)
		exit(1);
	fdf->map->splited[i] = NULL;
	i = -1;
	while (matrix[++i])
	{
		fdf->map->splited[i] = ft_rdinfo(ft_split(matrix[i], 32));
		if (!fdf->map->splited[i])
			exit(1);
		free(matrix[i]);
	}
	free(matrix);
}

void	ft_parse_map(char *map, t_main *fdf)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free(map);
		ft_print_error(fdf, "Error map data");
	}
	while (map[++i])
		if (map[i] == '\n' && (map[i + 1] == '\n' || map[i + 1] == '\0'))
			break ;
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
		exit(1);
	buff = read(fd, file_buff, file_len + 1);
	if (!buff)
		exit(1);
	file_buff[buff] = '\0';
	ft_parse_map(file_buff, fdf);
	file_to_map(fdf, ft_split(file_buff, '\n'));
	free(file_buff);
	close(fd);
}
