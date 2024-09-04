/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:38:10 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/04 14:11:18 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIN_X
#  define WIN_X 1920
# endif

# ifndef WIN_Y
#  define WIN_Y 1060
# endif

# ifndef SPACE
#  define SPACE 10
# endif

# ifndef ZSPACE
#  define ZSPACE 5
# endif

# ifndef BACK_COLOR
#  define BACK_COLOR 0x202020
# endif

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_map_info
{
	int			x;
	int			y;
	int			value;
	int			color;
}				t_map_info;

typedef struct s_map
{
	t_map_info	***map_data;
	char		**map;
	int			max_x;
	int			max_y;
}				t_map;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
}				t_img;

typedef struct s_main
{
	t_map		*map;
	t_img		*mlx_img;
	t_point		*pts;
	void		*mlx;
	void		*win;
	char		*win_title;
}				t_main;

t_map_info		**ft_get_info(char **matrix, t_main *fdf, int j);

t_point			ft_sub(t_point pt0, t_point pt1);
t_point			ft_add(t_point pt0, t_point pt1);
t_point			ft_right(t_point pt0, t_point pt1, t_main *fdf);
t_point			ft_down(t_point pt0, t_point pt1, t_main *fdf);
t_point			ft_center(t_point offset, t_main *data);

int				ft_draw_line_right(t_img *img, t_point start, t_point end);
int				ft_draw_line_down(t_img *img, t_point start, t_point end);
int				ft_draw_line(t_img *img, t_point start, t_point end);
int				ft_xclose_win(t_main *fdf);
int				ft_close_win(int key, t_main *fdf);
int				ft_loop_hook(t_main *data);
int				ft_file_len(char *file);
int				ft_atoh(char *matrix);
int				colr(t_point cur, t_point start, t_point end, t_point d);

void			ft_init(char *file);
void			ft_check_file_ext(char *file);
void			ft_check_file(char *file);
void			ft_read_map(t_main *fdf, char *file);
void			ft_check_map(char *map, t_main *fdf);
void			ft_draw_start(t_main *fdf);
void			ft_draw_background(t_img *img, int color);
void			ft_draw(t_img *img, t_main *map, t_point offset);
void			ft_iso_projection(t_point *pt);
void			ft_pixel_put(t_img *img, t_point pt);
void			ft_print_error(t_main *fdf, char *msg_error);
void			ft_file_to_map(t_main *fdf, char **matrix);
void			ft_free_map_data(t_main *fdf);
void			ft_free_map(t_main *map);
void			ft_mlx_exit(t_main *fdf);

#endif
