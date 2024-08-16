/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:16:00 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/14 16:16:02 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(int key, t_main *mlx)
{
	if (key == 65307)
	{
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		free(mlx->title);
		free(mlx);
		exit(0);
	}
	return (0);
}

int	ft_close_button(t_main *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free(mlx->title);
	free(mlx);
	exit(0);
}
