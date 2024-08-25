/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:18:58 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/25 08:46:29 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	close_win(int key, t_main *fdf)
{
	if (key == 65307)
		mlx_exit(fdf);
	return (0);
}

int	xclose_win(t_main *fdf)
{
	mlx_exit(fdf);
	return (0);
}
