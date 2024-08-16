/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:39:07 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/16 08:39:09 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_pixel_put(t_main *data, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = data->addr + (y * data->line_length + x * (data->bpp / 8));
// 	*(unsigned int *)pixel = color;
// }

// void	ft_center(t_draw *point, t_offset *offset)
// {
// 	int	center_x;
// 	int	center_y;

// 	center_x = WIDTH / 2;
// 	center_y = HEIGHT / 2;
// 	offset->x = (center_x) - ((point->x0 + point->x1) / 2);
// 	offset->y = (center_y) - ((point->y0 + point->y1) / 2);
// }

// void	draw_line(t_draw *point, t_main *data)
// {
// 	t_offset	offset;

// 	ft_center(point, &offset);
// 	point->x1 += offset.x;
// 	point->y1 += offset.y;
// 	point->x = point->x0 + offset.x;
// 	point->y = point->y0 + offset.y;
// 	point->dx = point->x1 - point->x0;
// 	point->dy = point->y1 - point->y0;
// 	point->d = 2 * (point->dy - point->dx);
// 	while (point->x <= point->x1)
// 	{
// 		ft_pixel_put(data, point->x, point->y, 0xffffff);
// 		if (point->d >= 0)
// 		{
// 			point->d += (2 * point->dy) - (2 * point->dx);
// 			point->y = point->y + 1;
// 		}
// 		else
// 			point->d += 2 * point->dy;
// 		point->x = point->x + 1;
// 	}
// }