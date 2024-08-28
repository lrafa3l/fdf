/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:22:40 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:09:55 by lrafael          ###   ########.fr       */
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
