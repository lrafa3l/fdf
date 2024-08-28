/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:18:58 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:10:51 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_process(t_main *data)
{
	t_point	offset;

	if (!data->win)
		exit (1);
	ft_draw_background(data->mlx_img, CBLACK);
	offset.x = (WIN_X / 2) - ((data->map->x * SPACE) / 2);
	offset.y = (WIN_Y / 2) - ((data->map->y * SPACE) / 2);
	offset.z = 0;
	ft_draw(data->mlx_img, data, offset);
	mlx_put_image_to_window(data->mlx, data->win, data->mlx_img->img, 0, 0);
}

int	ft_close_win(int key, t_main *fdf)
{
	if (key == 65307)
		ft_mlx_exit(fdf);
	return (0);
}

int	ft_xclose_win(t_main *fdf)
{
	ft_mlx_exit(fdf);
	return (0);
}
