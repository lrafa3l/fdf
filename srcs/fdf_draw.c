/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:22:29 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/03 17:26:25 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_draw(t_img *img, t_main *fdf, t_point offset)
{
	t_point	pt;

	pt.y = -1;
	while (++pt.y < fdf->map->max_y)
	{
		pt.x = -1;
		while (++pt.x < fdf->map->max_x)
		{
			pt.z = fdf->map->map_data[pt.y][pt.x]->value;
			pt.color = fdf->map->map_data[pt.y][pt.x]->color;
			if (pt.x + 1 < fdf->map->max_x)
				ft_draw_line(img, ft_add(pt, offset), ft_right(pt, offset,
						fdf));
			if (pt.y + 1 < fdf->map->max_y)
				ft_draw_line(img, ft_add(pt, offset), ft_down(pt, offset, fdf));
		}
	}
}

void	ft_draw_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_Y)
	{
		j = -1;
		while (++j < WIN_X)
			ft_pixel_put(img, (t_point){j, i, 0, color});
	}
}

void	ft_draw_start(t_main *data)
{
	t_point	offset;

	if (!data->win)
		exit(1);
	ft_draw_background(data->mlx_img, BACK_COLOR);
	ft_draw(data->mlx_img, data, ft_center(offset, data));
}
