/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:55:05 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:10:34 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_check_file_ext(char *file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
		i++;
	if (i == 4)
	{
		ft_printf("\033[H\033[J'%s%s%s' is an invalid file.\n", RED, file,
			RESET);
		exit(1);
	}
	i--;
	j = 3;
	while (j >= 0)
	{
		if (file[i--] != ".fdf"[j--])
		{
			ft_printf("\033[H\033[J'%s%s%s' is an invalid extention,\
 it must be: <*.fdf>.\n", RED, file, RESET);
			exit(1);
		}
	}
}

void	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_printf("\033[H\033[J'%s%s%s' does not exist.\n", RED, file, RESET);
	if (fd == -1)
		exit(1);
	close(fd);
}
