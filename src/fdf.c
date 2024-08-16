/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:46:00 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/12 09:46:01 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	_map_free(t_main *_main)
// {
// 	int	i;

// 	i = 0;
// 	while (_main->map[i])
// 		free(_main->map[i++]);
// 	free(_main->map);
// }

static void	_init(t_main *_main)
{
	ft_check_ext(_main);
	ft_read_file(_main);
	ft_parse_map(_main);
	ft_mlx(_main);
	//ft_take_data(_main);
	//_map_free(_main);
}

int	main(int argc, char *argv[])
{
	t_main	*_main;

	_main = (t_main *)malloc(sizeof(t_main));
	if (!_main)
		return (1);
	if (argc == 2)
	{
		_main->file = argv[1];
		_init(_main);
	}
	else
		p_error("It's missing paramater, or are too much :(");
	free(_main);
	return (0);
}
