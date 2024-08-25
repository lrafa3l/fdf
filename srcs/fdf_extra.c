/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:43:12 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/25 08:45:51 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	free_splited(t_main *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (fdf->map->splited[i])
	{
		j = 0;
		while (fdf->map->splited[i][j])
			free(fdf->map->splited[i][j++]);
		free(fdf->map->splited[i++]);
	}
	free(fdf->map->splited[i]);
	free(fdf->map->splited);
}

void	mlx_exit(t_main *fdf)
{
	if (fdf->map->splited)
		free_splited(fdf);
	if (fdf->map)
		free(fdf->map);
	// if (fdf->img)
	// 	mlx_destroy_image(fdf->mlx, fdf->img);
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

void	ft_print_error(t_main *fdf, char *error_message)
{
	ft_printf("\033[H\033[J%s%s%s%s\n", RED, BOLD, error_message, RESET);
	mlx_exit(fdf);
}
