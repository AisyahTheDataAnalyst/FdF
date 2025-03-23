/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:30:28 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/21 10:24:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx.h"
// #include <stdio.h>
// #include <math.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// #define WIDTH 800
// #define HEIGHT 600

// // putting in pixels into the window
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void    draw_circle(t_data *data, int xc, int yc, int r, int color)
// {
//     int x = 0;
//     int y = r;
//     int p = 1 - r;

//     while (x <= y)
//     {
//         my_mlx_pixel_put(data, xc + x, yc + y, color);
//         my_mlx_pixel_put(data, xc - x, yc + y, color);
//         my_mlx_pixel_put(data, xc + x, yc - y, color);
//         my_mlx_pixel_put(data, xc - x, yc - y, color);
//         my_mlx_pixel_put(data, xc + y, yc + x, color);
//         my_mlx_pixel_put(data, xc - y, yc + x, color);
//         my_mlx_pixel_put(data, xc + y, yc - x, color);
//         my_mlx_pixel_put(data, xc - y, yc - x, color);

//         if (p < 0)
//             p = p + 2 * x + 3;
//         else
//         {
//             p = p + 2 * (x - y) + 5;
//             y--;
//         }
//         x++;
//     }
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
// 	draw_circle(&img, WIDTH / 2, HEIGHT / 2, 100, 0x00FF0000); // Draw a red circle

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// ______________________________________________________________________/

// #include <stdio.h>
// #include <math.h>
// #include "mlx.h"

// #define WIDTH 800
// #define HEIGHT 600

// typedef struct s_data {
//     void    *mlx;
//     void    *win;
//     void    *img;
//     char    *addr;
//     int     bits_per_pixel;
//     int     line_length;
//     int     endian;
// } t_data;

// void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }



// int main(void)
// {
//     t_data  data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Circle Drawing");
//     data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
//     data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

//     draw_circle(&data, WIDTH / 2, HEIGHT / 2, 100, 0x00FF0000); // Draw a red circle

//     mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
//     mlx_loop(data.mlx);
//     return (0);
// }