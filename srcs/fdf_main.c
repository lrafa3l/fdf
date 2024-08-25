/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:38:59 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/25 08:46:48 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_and_structs_init(t_main *mlx, char *title)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->win_title = ft_strjoin("Lando's FDF - ", title);
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, mlx->win_title);
	if (!mlx->win)
		exit(1);
	mlx->map = (t_map *)malloc(sizeof(t_map));
	if (!mlx->map)
		exit(1);
	mlx->map->splited = NULL;
	// mlx->img = (t_img *)malloc(sizeof(t_img));
	// if (!mlx->img)
	// 	exit(1);
}

void	ft_init(char *file)
{
	t_main	*fdf;

	ft_check_file_ext(file);
	ft_check_file(file);
	fdf = (t_main *)malloc(sizeof(t_main));
	if (!fdf)
		exit(1);
	mlx_and_structs_init(fdf, file);
	ft_read_map(fdf, file);
	mlx_key_hook(fdf->win, close_win, fdf);
	mlx_hook(fdf->win, 17, 1L << 0, xclose_win, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("%sInvalid args!%s\n", RED, RESET);
	if (argc != 2)
		return (-1);
	ft_init(argv[1]);
	return (0);
}
