/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:42:02 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/12 09:42:12 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1900
# define HEIGHT 1000

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_main
{
	void	*connection;
	void	*window;
	void	*image;
	char	*title;
	char	*addr;
	char	*file;
	char	*line;
	char	**got_from_file;
	int		width;
	int		height;
	int		fd;
	int		**map;
	int		x;
	int		y;
	int		z;
	int		bpp;
	int		line_length;
	int		endian;
	int		scale;
}			t_main;

typedef struct s_offset
{
	int		x;
	int		y;
}			t_offset;

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	int		z;
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		x2;
	int		y2;
	int		z2;
}			t_draw;

void		ft_file_init(t_main *file);
void		ft_read_file(t_main *file);
void		ft_check_ext(t_main *title);
void		ft_parse_map(t_main *file);
void		ft_mlx(t_main *mlx);
void		*mlx_error(void *ptr, char *error_msg, t_main *mlx);
void		ft_take_data(t_main *data);
void		ft_pixel_put(t_main *data, int x, int y, int color);
void		x_axis(t_main *data, int x, int y);
void		y_axis(t_main *data, int x, int y);

int			p_error(char *error);
int			ft_close(int key, t_main *mlx);
int			ft_close_button(t_main *mlx);

#endif
