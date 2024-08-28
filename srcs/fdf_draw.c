/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:22:29 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:09:41 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_draw_line_right(t_img *img, t_point start, t_point end)
{
	int		delta;
	int		xi;
	t_point	d;
	t_point	cur;

	d = ft_sub(end, start);
	xi = 1;
	if (d.x < 0)
		xi = -1;
	d.x = abs(d.x);
	delta = (2 * d.x) - d.y;
	cur = start;
	while (cur.y <= end.y)
	{
		ft_pixel_put(img, cur);
		if (delta > 0)
		{
			cur.x += xi;
			delta += 2 * (d.x - d.y);
		}
		else
			delta += 2 * d.x;
		cur.y++;
	}
	return (0);
}

int	ft_draw_line_down(t_img *img, t_point start, t_point end)
{
	int		delta;
	int		yi;
	t_point	d;
	t_point	cur;

	d = ft_sub(end, start);
	yi = 1;
	if (d.y < 0)
		yi = -1;
	d.y = abs(d.y);
	delta = (2 * d.y) - d.x;
	cur = start;
	while (cur.x <= end.x)
	{
		ft_pixel_put(img, cur);
		if (delta > 0)
		{
			cur.y += yi;
			delta += 2 * (d.y - d.x);
		}
		else
			delta += 2 * d.y;
		cur.x++;
	}
	return (0);
}

int	ft_draw_line(t_img *img, t_point start, t_point end)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			return (ft_draw_line_down(img, end, start));
		else
			return (ft_draw_line_down(img, start, end));
	}
	else
	{
		if (start.y > end.y)
			return (ft_draw_line_right(img, end, start));
		else
			return (ft_draw_line_right(img, start, end));
	}
	return (-1);
}

void	ft_draw(t_img *img, t_main *fdf, t_point offset)
{
	t_point	i;
	t_point	right;
	t_point	down;

	i.y = -1;
	while (++i.y < fdf->map->y)
	{
		i.x = -1;
		while (++i.x < fdf->map->x)
		{
			i.z = fdf->map->z[i.y][i.x]->value;
			i.color = fdf->map->z[i.y][i.x]->color;
			if (i.x + 1 < fdf->map->x)
			{
				right = ft_right(i, offset, fdf);
				ft_draw_line(img, ft_add(i, offset), right);
			}
			if (i.y + 1 < fdf->map->y)
			{
				down = ft_down(i, offset, fdf);
				ft_draw_line(img, ft_add(i, offset), down);
			}
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
