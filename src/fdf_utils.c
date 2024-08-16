/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:08:26 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/12 12:08:29 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	p_error(char *error)
{
	if (!error)
		ft_printf("\033[H\033[J%s%sERROR%s\n", RED, BOLD, RESET);
	else
		ft_printf("\033[H\033[J%s%s%s%s\n", RED, BOLD, error, RESET);
	exit(1);
}

void	*mlx_error(void *ptr, char *error_msg, t_main *mlx)
{
	if (!ptr)
	{
		p_error(error_msg);
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		exit(1);
	}
	else
		return (ptr);
}

void	ft_check_ext(t_main *title)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (".fdf"[i])
	{
		j = 0;
		while (title->file[j])
		{
			if (".fdf"[i] == title->file[j])
				i++;
			j++;
		}
		if (".fdf"[i] == '\0')
			ft_printf("\033[H\033[J%s%sGood file extention! ;)%s\n", GREEN,
				BOLD, RESET);
		else
		{
			free(title);
			p_error("Invalid file extention :(");
			break ;
		}
	}
}

void	ft_mlx(t_main *mlx)
{
	mlx->title = ft_strjoin("Lando's FDF - ", mlx->file);
	mlx->connection = mlx_init();
	mlx_error(mlx->connection, "MLX connection failed.", mlx);
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, mlx->title);
	mlx_error(mlx->window, "MLX window failed.", mlx);
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	mlx_error(mlx->image, "MLX image failed.", mlx);
	mlx->addr = mlx_get_data_addr(&mlx->image, &mlx->bpp, &mlx->line_length,
			&mlx->endian);
	mlx_error(mlx->addr, "MLX address failed.", mlx);
	mlx_key_hook(mlx->window, ft_close, mlx);
	mlx_hook(mlx->window, 17, 0L, ft_close_button, mlx);
	mlx_loop(mlx->connection);
	mlx_destroy_image(mlx->connection, mlx->window);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free(mlx->title);
}
