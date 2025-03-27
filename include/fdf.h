/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:07:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/27 15:06:08 by aimokhta         ###   ########.fr       */
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
	int		row;
	int		column;
}	t_map;

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}	t_data;

//////// parsing ////////
//1.1 parsing.c
void			parse_map_row(char **av, t_map *map);
void			parse_column_colour_z(t_map *map, int i, char **row_values);
void			parse_colour_z_unique(char **split, t_pixel *pixel);
void			parse_colour_z_normal(t_pixel *pixel, char **row_values, int j);
void			parse_x_y(t_map *map, t_pixel *pixel, int i, int j);
//1.2 parsing_helper.c
void			counting_row_col(char **av, t_map *map);
size_t			ft_wordcount(char const *s, char c);
int				char_to_hex(char c);
unsigned int	ft_atoi_base_unsigned(const char *str, int str_base);
//1.3 parsing_freeing.c
void			freeing_split(char **split);
void			free_map(t_map *map);
void			free_line_row_values(char *line, char **row_values);

//////// minilibx ////////
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_window(int keycode, t_data *data);



//////// isometric ////////

//////// bresenham ////////

#endif