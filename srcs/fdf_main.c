/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:38:59 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/03 17:27:48 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	mlx_and_structs_init(t_main *fdf, char *title)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit(1);
	fdf->win_title = ft_strjoin("Lando's FDF - ", title);
	fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, fdf->win_title);
	if (!fdf->win)
		exit(1);
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		exit(1);
	fdf->mlx_img = (t_img *)malloc(sizeof(t_img));
	if (!fdf->mlx_img)
		exit(1);
	fdf->mlx_img->img = mlx_new_image(fdf->mlx, WIN_X, WIN_Y);
	if (!fdf->mlx_img->img)
		exit(1);
	fdf->mlx_img->addr = mlx_get_data_addr(fdf->mlx_img->img,
			&fdf->mlx_img->bpp, &fdf->mlx_img->l_len, &fdf->mlx_img->endian);
	fdf->pts = (t_point *)malloc(sizeof(t_point));
	if (!fdf->pts)
		exit(1);
	fdf->map->z = NULL;
	fdf->map->map = NULL;
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
	ft_draw_start(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_img->img, 0, 0);
	mlx_key_hook(fdf->win, ft_close_win, fdf);
	mlx_hook(fdf->win, 17, 1L << 0, ft_xclose_win, fdf);
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
