/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:38:10 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/26 10:12:14 by lrafael          ###   ########.fr       */
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
	int			z;
	int			color;
}				t_z_info;

typedef struct s_map
{
	int			x;
	int			y;
	int			z;
	int			fd;
	t_z_info	***splited;
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

t_z_info		**ft_rdinfo(char **matrix);

int				close_win(int key, t_main *fdf);
int				xclose_win(t_main *fdf);
int				ft_file_len(char *file);
int				ft_atoh(char *matrix);
int				l_hook(t_main *data);

void			ft_print_error(t_main *fdf, char *error_message);
void			file_to_map(t_main *fdf, char **matrix);
void			draw_background(t_img *img, int color);
void			ft_parse_map(char *map, t_main *fdf);
void			ft_read_map(t_main *fdf, char *file);
void			ft_pixel_put(t_img *img, t_point pt);
void			ft_check_file_ext(char *file);
void			ft_check_file(char *file);
void			free_splited(t_main *fdf);
void			mlx_exit(t_main *fdf);
void			ft_init(char *file);

#endif
