/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:59:59 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:11:30 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

t_point	ft_right(t_point pt0, t_point pt1, t_main *fdf)
{
	t_point	sum;

	pt0.z = fdf->map->z[pt0.y][pt0.x + 1]->value;
	pt0.color = fdf->map->z[pt0.y][pt0.x + 1]->color;
	sum.x = (SPACE * (pt0.x + 1)) + pt1.x;
	sum.y = (SPACE * pt0.y) + pt1.y;
	sum.z = (ZSPACE * pt0.z) + pt1.z;
	sum.color = pt0.color;
	ft_iso_projection(&sum);
	return (sum);
}

t_point	ft_down(t_point pt0, t_point pt1, t_main *fdf)
{
	t_point	sum;

	pt0.z = fdf->map->z[pt0.y + 1][pt0.x]->value;
	pt0.color = fdf->map->z[pt0.y + 1][pt0.x]->color;
	sum.x = (SPACE * pt0.x) + pt1.x;
	sum.y = (SPACE * (pt0.y + 1)) + pt1.y;
	sum.z = (ZSPACE * pt0.z) + pt1.z;
	sum.color = pt0.color;
	ft_iso_projection(&sum);
	return (sum);
}

t_point	ft_add(t_point pt0, t_point pt1)
{
	t_point	sum;

	sum.x = (SPACE * pt0.x) + pt1.x;
	sum.y = (SPACE * pt0.y) + pt1.y;
	sum.z = (ZSPACE * pt0.z) + pt1.z;
	sum.color = pt0.color;
	ft_iso_projection(&sum);
	return (sum);
}

t_point	ft_sub(t_point pt0, t_point pt1)
{
	t_point	diff;

	diff.x = pt0.x - pt1.x;
	diff.y = pt0.y - pt1.y;
	diff.z = pt0.z - pt1.z;
	diff.color = pt0.color;
	return (diff);
}
