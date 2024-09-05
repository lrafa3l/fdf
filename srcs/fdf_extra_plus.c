/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extra_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:58:10 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/05 14:51:13 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_max_z(t_main *fdf, int n)
{
	if (fdf->map->max_z < n)
		fdf->map->max_z = n;
}

int	ft_min_size(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_verif_parse_x(char **matrix, t_main *fdf)
{
	int	mx;
	int	i;

	mx = 0;
	while (matrix[mx] != NULL)
		mx++;
	if (fdf->map->max_x != 0 && fdf->map->max_x != mx)
	{
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
		ft_mlx_exit(fdf);
	}
	return (mx);
}

void	ft_data_init(t_map_info **data, t_main *fdf)
{
	int	i;

	i = -1;
	while (++i < fdf->map->max_x + 1)
		data[i] = NULL;
}
