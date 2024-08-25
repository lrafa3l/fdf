/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:38:10 by lrafael           #+#    #+#             */
/*   Updated: 2024/08/25 08:48:02 by lrafael          ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

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
	t_img		*img;
	void		*mlx;
	void		*win;
	char		*win_title;
}				t_main;

t_z_info		**ft_rdinfo(char **matrix);

int				close_win(int key, t_main *fdf);
int				xclose_win(t_main *fdf);
int				ft_file_len(char *file);
int				ft_atoh(char *matrix);

void			ft_check_file(char *file);
void			ft_print_error(t_main *fdf, char *error_message);
void			file_to_map(t_main *fdf, char **matrix);
void			ft_parse_map(char *map, t_main *fdf);
void			ft_read_map(t_main *fdf, char *file);
void			ft_check_file_ext(char *file);
void			free_splited(t_main *fdf);
void			mlx_exit(t_main *fdf);
void			ft_init(char *file);

#endif
