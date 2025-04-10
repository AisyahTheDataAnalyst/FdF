/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:07:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/10 17:41:09 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// buttons
# define ESC_BUTTON 65307	// MacOS 53, Linux 65307

// keyword
# define WIN_WIDTH 3800 	//1920 //3840
# define WIN_HEIGHT 2000 	//1080 //2160
# define ISO_ANGLE 0.523599	// = 30°
# define ISO_SCALE 10		// adjust to control the zoom level
# define Z_SCALE 10			// adjust for z height amplifier
# define COMPRESSION 1		// adjust the compression of the map
# define DEFAULT_COLOUR 0xFFFFFF	// white

// # include <mlx.h>
// # include <mlx_int.h>
// # include "libft.h"
// # include "ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>			// open
# include <unistd.h>		// close
# include <stdlib.h>		//abs
# include <math.h>			// sin, cos

typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	int		ori_x;
	int		ori_y;
	int		ori_z;
	int		colour;
}	t_pixel;

typedef struct s_map
{
	t_pixel	**grid;
	int		height;
	int		width;
}	t_map;

typedef struct s_line
{
	t_pixel	a;		// start (1st coordinate)
	t_pixel	b;		// end (2nd coordinate, not last coordinate of the line)
	int		dx;		// differences between x1 and x0
	int		dy;		// differences between y1 and y0
	int		err;	// error/decision parameter when to adjust Y position
	int		x_inc;	// x_increment direction (1 / -1)
	int		y_inc;	// y_increment direction (1 / -1)
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
	t_map	map;
	t_pixel	pixel;
	t_line	line;
}	t_mlx;

// ---------- parsing ----------
//		1.1 main parsing
void	parse_map_height(char **av, t_map *map, t_pixel *pixel);
void	parse_width(t_map *map, int i, char **height_values, t_pixel *pixel);
void	parse_colour_z_unique(char **split, t_pixel *pixel);
void	parse_colour_z_normal(t_pixel *pixel, char **height_values, int j);
void	parse_x_y(t_map *map, t_pixel *pixel, int i, int j);

//		1.2 parsing helper
void	counting_height_width(char **av, t_map *map);
size_t	ft_wordcount(char const *s, char c);
int		char_to_hex(char c);
int		ft_atoi_base(const char *str, int str_base);

//		1.3 freeing parsing
void	freeing_split(char **split);
void	free_map(t_map *map);
void	free_line_height_values(char *line, char **height_values);

//---------- mlx_functions ----------
void	fdf_init(t_mlx *mlx);
void	my_mlx_pixel_put(t_img *img, int x, int y, int colour);
int		close_window_esc(int keycode, t_mlx *mlx);
int		close_window_x(t_mlx *mlx);
void	cleanup(t_mlx *mlx);

//---------- bresenham ----------
//		1.1 horizontal
void	draw_line_h(t_img *img, t_line *line, t_map *map);
void	prepare_params_h(t_line *line, t_map *map, int column, int row);
void	bresenham(t_line *line, t_img *img);
void	bresenham_formula(t_line *line, int *x, int *y);

//		1.2 vertical
void	draw_line_v(t_img *img, t_line *line, t_map *map);
void	prepare_params_v(t_line *line, t_map *map, int row, int column);

// ---------- colour ---------- (got some static functions)
int		gradient(t_line *line, t_pixel *current);

// ---------- isometric ---------- (got some static functions)
void	isometric(t_map *map);

#endif