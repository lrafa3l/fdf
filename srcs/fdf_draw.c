/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:22:29 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/26 10:12:51 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_pixel_put(t_img *img, t_point pt)
{
	char	*pxl;
	int		x;
	int		y;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	pxl = img->addr + y * img->l_len + x * (img->bpp / 8);
	*(int *)pxl = pt.color;
}

void	draw_background(t_img *img, int color)
{
	int i;
	int j;
    
	i = -1;
	while (++i < WIN_Y)
	{
		j = -1;
		while (++j < WIN_X)
			ft_pixel_put(img, (t_point){j, i, 0, color});
	}
}
