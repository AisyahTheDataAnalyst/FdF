/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:07:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/29 16:12:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
// # include <mlx.h>
// # include <mlx_int.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h> // open
# include <unistd.h> // close
// # include <stdlib.h> //donno
# include <stdio.h> // remove later for printf, perror

// MacOS 53, Linux 65307
# define ESC_BUTTON 65307

typedef struct s_pixel
{
	int				x;
	int				y;
	int				z;
	unsigned int	colour;
}	t_pixel;

typedef struct s_map
{
	t_pixel	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_line
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		dir;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	picture;
	t_map	mapping;
}	t_mlx;


// ---------- parsing ----------
//1.1 parsing.c
void			parse_map_height(char **av, t_map *map);
void			parse_width_colour_z(t_map *map, int i, char **height_values);
void			parse_colour_z_unique(char **split, t_pixel *pixel);
void		parse_colour_z_normal(t_pixel *pixel, char **height_values, int j);
void			parse_x_y(t_map *map, t_pixel *pixel, int i, int j);
//1.2 parsing_helper.c
void			counting_height_width(char **av, t_map *map);
size_t			ft_wordcount(char const *s, char c);
int				char_to_hex(char c);
unsigned int	ft_atoi_base_unsigned(const char *str, int str_base);
//1.3 parsing_freeing.c
void			freeing_split(char **split);
void			free_map(t_map *map);
void			free_line_height_values(char *line, char **height_values);

//---------- minilibx ----------
void			fdf_init(t_mlx *mlx);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				close_window_esc(int keycode, t_mlx *mlx);
int				close_window_x(t_mlx *mlx);
void 	cleanup(t_mlx *mlx);
//---------- isometric ----------

//---------- bresenham ----------
void	draw_line_h(t_img *img, t_line *line, t_map *map, unsigned int colour);
void	preparing_params_draw_line(t_line *line, t_map *map);
#endif