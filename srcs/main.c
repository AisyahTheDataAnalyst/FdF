/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:42:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/22 10:23:53 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

// typedef struct s_data 
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	void	*mlx;
// 	void	*win;
// }				t_data;

// // // putting in pixels into the window
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	close(int keycode, t_data *data)
// {
// 	(void)keycode;
// 	mlx_destroy_window(data->mlx, data->win);
// 	return (0);
// }

//purpose : 
// mlx_init
// 	- to initialize MiniLibX 
//	- establish a connection to correct graphical system, return void* holds location of our current MLX instance
// mlx_new_window
//	- open a window, return a pointer to the window that we just created
// mlx_new_image
//	- creating an image- buffer pixels to image the well push to the window
// mlx_get_data_addr 
//	- creating an image addr - after creating an image, we pass all the referenced ones to be set accordingly for the current data address 
// my_mlx_pixel_put 
//	- putting 1 pixel only into the image - with starting x starting y and color
// mlx_put_image_to_window
//	- as the name stated
// mlx_loop
//	- open windows until we cntrlD at the terminal  - initiate window rendering


// int	main(void)
// {
// 	t_data	img;

// 	img.mlx = mlx_init();
// 	img.win = mlx_new_window(img.mlx, 1920, 1080, "Welcome to aimokhta's FdF! :)");
// 	img.img = mlx_new_image(img.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	// my_mlx_pixel_put(&img, 1920/2, 1080/2, 0x00FF0000); // just a pixel
// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	mlx_hook(img.win, 2, 1L<<0, close, &img);
// 	mlx_loop(img.mlx);
// }
