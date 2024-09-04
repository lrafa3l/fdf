/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:22:40 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/04 14:11:50 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_pixel_put(t_img *img, t_point pt)
{
	char	*pxl;
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	pxl = img->addr + y * img->l_len + x * (img->bpp / 8);
	*(int *)pxl = pt.color;
}

void	ft_iso_projection(t_point *pt)
{
	int	tmp;

	tmp = pt->x;
	pt->x = (tmp - pt->y);
	pt->y = ((tmp + pt->y) / 2) - pt->z;
}

static int	inter_color(t_point start, t_point end, float t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((start.color >> 16) & 0xFF) + t
			* ((end.color >> 16) & 0xFF));
	g = (int)((1 - t) * ((start.color >> 8) & 0xFF) + t
			* ((end.color >> 8) & 0xFF));
	b = (int)((1 - t) * (start.color & 0xFF) + t * (end.color & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

int	colr(t_point cur, t_point start, t_point end, t_point d)
{
	float	distance;
	float	n_distance;

	distance = sqrt((cur.x - start.x) * (cur.x - start.x) + (cur.y - start.y)
			* (cur.y - start.y));
	n_distance = distance / sqrt(d.x * d.x + d.y * d.y);
	return (inter_color(start, end, n_distance));
}

t_point	ft_center(t_point offset, t_main *fdf)
{
	offset.x = (WIN_X / 3 + 350) - ((fdf->map->max_x / 2) * SPACE);
	offset.y = (WIN_Y / 3 - 350) - ((fdf->map->max_y / 2) * SPACE);
	offset.z = 0;
	return (offset);
}
