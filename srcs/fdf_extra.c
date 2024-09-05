/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:43:12 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/05 14:51:25 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_free_map(t_main *map)
{
	int	i;

	i = 0;
	while (map->map->map[i])
		free(map->map->map[i++]);
	free(map->map->map);
}

void	ft_free_map_data(t_main *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (fdf->map->map_data[++i])
	{
		j = -1;
		while (fdf->map->map_data[i][++j])
			free(fdf->map->map_data[i][j]);
		free(fdf->map->map_data[i]);
	}
	free(fdf->map->map_data);
}

void	ft_mlx_exit(t_main *fdf)
{
	if (fdf->map->map_data)
		ft_free_map_data(fdf);
	if (fdf->map->map)
		ft_free_map(fdf);
	if (fdf->map)
		free(fdf->map);
	if (fdf->pts)
		free(fdf->pts);
	if (fdf->mlx_img->img)
		mlx_destroy_image(fdf->mlx, fdf->mlx_img->img);
	if (fdf->mlx_img)
		free(fdf->mlx_img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->win_title)
		free(fdf->win_title);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->mlx)
		free(fdf->mlx);
	if (fdf)
		free(fdf);
	exit(0);
}

int	ft_file_len(char *file)
{
	int		len;
	int		fd;
	int		i;
	char	buff[BUFFER_SIZE];

	fd = open(file, O_RDONLY);
	len = 0;
	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		len += i;
	}
	close(fd);
	return (len);
}

void	ft_print_error(t_main *fdf, char *msg_error)
{
	ft_printf("\033[H\033[J%s%s%s%s\n", RED, BOLD, msg_error, RESET);
	ft_mlx_exit(fdf);
}
