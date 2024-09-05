/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:34:37 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/05 14:50:51 by lrafael          ###   ########.fr       */
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
		ft_pixel_put(img, (t_point){cur.x, cur.y, 0, colr(cur, start, end, d)});
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
		ft_pixel_put(img, (t_point){cur.x, cur.y, 0, colr(cur, start, end, d)});
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
