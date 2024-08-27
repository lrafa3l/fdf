/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:38:10 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/27 06:11:58 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIN_X
#  define WIN_X 1440
# endif

# ifndef WIN_Y
#  define WIN_Y 900
# endif

# define CRED 0xFF0000
# define CGREEN 0x00FF00
# define CBLUE 0x0000FF
# define CWHITE 0xFFFFFF
# define CBLACK 0x000000
# define CYELLOW 0xFFFF00
# define CCYAN 0x00FFFF
# define CMAGENTA 0xFF00FF

# define CGRAY 0x808080
# define CLGRAY 0xD3D3D3
# define CDGRAY 0xA9A9A9

# define CLRED 0xFFCCCC
# define CDRED 0x8B0000

# define CLGREEN 0x90EE90
# define CDGREEN 0x006400

# define CLBLUE 0xADD8E6
# define CDBLUE 0x00008B

# define CLPURPLE 0xD8BFD8
# define CDPURPLE 0x4B0082

# define CLORANGE 0xFFDAB9
# define CDORANGE 0xFF8C00

# define CLBROWN 0xA0522D
# define CDBROWN 0x8B4513

# define CTURQUOISE 0x40E0D0
# define CTEAL 0x008080
# define CINDIGO 0x4B0082
# define CVIOLET 0xEE82EE
# define CNAVY 0x000080

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_z_info
{
	int			x;
	int			y;
	int			value;
	int			color;
}				t_z_info;

// typedef struct s_delta
// {

// }				t_delta;

typedef struct s_map
{
	t_z_info	***z;
	char		**map;
	int			x;
	int			y;
}				t_map;

typedef struct s_point
{
	float_t		x;
	float_t		y;
	float_t		z;
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

t_z_info		**ft_rdinfo(char **matrix, t_main *axis, int j);
t_point			ft_sub(t_point pt0, t_point pt1);
t_point			ft_add(t_point pt0, t_point pt1);

int				ft_draw_line_right(t_img *img, t_point start, t_point end);
int				ft_draw_line_down(t_img *img, t_point start, t_point end);
int				ft_draw_line(t_img *img, t_point start, t_point end);
int				ft_close_win(int key, t_main *fdf);
int				ft_loop_hook(t_main *data);
int				ft_xclose_win(t_main *fdf);
int				ft_file_len(char *file);
int				ft_atoh(char *matrix);

void			ft_draw(t_img *img, t_main *map, t_point offset);
void			ft_print_error(t_main *fdf, char *msg_error);
void			ft_file_to_map(t_main *fdf, char **matrix);
void			ft_draw_background(t_img *img, int color);
void			ft_check_map(char *map, t_main *fdf);
void			ft_read_map(t_main *fdf, char *file);
void			ft_pixel_put(t_img *img, t_point pt);
void			ft_check_file_ext(char *file);
void			ft_free_zpoint(t_main *fdf);
void			ft_check_file(char *file);
void			ft_free_map(t_main *map);
void			ft_mlx_exit(t_main *fdf);
void			ft_init(char *file);

#endif
