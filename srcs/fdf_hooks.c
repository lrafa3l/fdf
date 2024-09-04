/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:18:58 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/04 14:12:34 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	ft_close_win(int key, t_main *fdf)
{
	if (key == 65307)
		ft_mlx_exit(fdf);
	return (0);
}

int	ft_xclose_win(t_main *fdf)
{
	ft_mlx_exit(fdf);
	return (0);
}
