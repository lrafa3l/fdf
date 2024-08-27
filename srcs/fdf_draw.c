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

// int	ft_draw_line_right(t_img *img, t_point start, t_point end)
// {
// 	int		delta;
// 	int		xi;
// 	t_point	d;
// 	t_point	cur;

// 	d = ft_sub(end, start);
// 	xi = 1;
// 	if (d.x < 0)
// 		xi = -1;
// 	d.x = fabsf(d.x);
// 	delta = (2 * d.x) - d.y;
// 	cur = start;
// 	while (cur.y < end.y)
// 	{
// 		ft_pixel_put(img, cur);
// 		if (delta > 0)
// 		{
// 			cur.x += xi;
// 			delta += 2 * (d.x - d.y);
// 		}
// 		else
// 			delta += 2 * d.x;
// 		cur.y++;
// 	}
// 	return (0);
// }

// int	ft_draw_line_down(t_img *img, t_point start, t_point end)
// {
// 	int		delta;
// 	int		yi;
// 	t_point	d;
// 	t_point	cur;

// 	d = ft_sub(end, start);
// 	yi = 1;
// 	if (d.y < 0)
// 		yi = -1;
// 	d.y = fabsf(d.y);
// 	delta = (2 * d.y) - d.x;
// 	cur = start;
// 	while (cur.x < end.x)
// 	{
// 		ft_pixel_put(img, cur);
// 		if (delta > 0)
// 		{
// 			cur.y += yi;
// 			delta += 2 * (d.y - d.x);
// 		}
// 		else
// 			delta += 2 * d.y;
// 		cur.x++;
// 	}
// 	return (0);
// }

// int	ft_draw_line(t_img *img, t_point start, t_point end)
// {
// 	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
// 	{
// 		if (start.x > end.x)
// 			return (ft_draw_line_down(img, end, start));
// 		else
// 			return (ft_draw_line_down(img, start, end));
// 	}
// 	else
// 	{
// 		if (start.y > end.y)
// 			return (ft_draw_line_right(img, end, start));
// 		else
// 			return (ft_draw_line_right(img, start, end));
// 	}
// 	return (-1);
// }

// void	ft_draw(t_img *img, t_main *map, t_point offset)
// {
// 	int		i;
// 	t_point	*cur;
// 	t_point	right;
// 	t_point	down;
// 	t_point	pt;

// 	i = 0;
// 	while (i < map->map->x * map->map->y)
// 	{
// 		cur = map->pts + i;
// 		pt = ft_add(*cur, offset);
// 		if (i % map->map->x != map->map->x - 1)
// 		{
// 			right = ft_add(*(cur + 1), offset);
// 			ft_draw_line(img, pt, right);
// 		}
// 		if (i < map->map->x * map->map->y - map->map->x)
// 		{
// 			down = ft_add(*(cur + map->map->x), offset);
// 			ft_draw_line(img, pt, down);
// 		}
// 		i++;
// 	}
// }

// void	ft_draw_linex(t_main *data, int x, int y)
// {

// }

// void	ft_draw_liney(t_main *data, int x, int y)
// {
	
// }

// void	ft_draw(t_main *data)
// {
// 	int x;
// 	int y;

// 	y = -1;
// 	while (++y < data->map->y)
// 	{
// 		x = -1;
// 		while (++x < data->map->x)
// 		{
// 			if (x < data->map->x - 1)
// 				ft_draw_linex(data, x, y);
// 			if (y < data->map->y - 1)
// 				ft_draw_liney(data, x, y);
// 		}
// 	}
// }

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
