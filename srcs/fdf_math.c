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

t_point	ft_add(t_point pt0, t_point pt1)
{
	t_point	sum;

	sum.x = pt0.x + pt1.x;
	sum.y = pt0.y + pt1.y;
	sum.z = pt0.z + pt1.z;
	sum.color = pt0.color;
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
