/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:42:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/14 16:06:58 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// // purpose : 
// // mlx_init
// // 	- to initialize MiniLibX 
// // 	- establish a connection to correct graphical system, 
// //   - return void* holds location of our current MLX instance
// // mlx_new_window
// // 	- open a window, return a pointer to the window that we just created
// // mlx_new_image
// // 	- creating an image- buffer pixels to image the well push to the window
// // mlx_get_img_addr 
// // 	- creating an image addr 
// //   - after creating an image, we pass all the referenced ones 
// //   - to be set accordingly for the current img address 
// // my_mlx_pixel_put 
// // 	- putting 1 pixel only into the image 
// //   - with starting x starting y and widthor
// // mlx_put_image_to_window
// // 	- as the name stated
// // mlx_loop
// // 	- open windows until we cntrlD at the terminal  
// //   - initiate window rendering
// // mlx_hook 
// // 	- a fn that assigns a callback to a specific window event
// // 	- 17 = sets up hook for Destroy	Notify event (event code 17)
// // 	- 1L<<0 = event mask (making sure hook triggers properly)
int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		exit(1);
	fdf_init(&mlx);
	counting_height_width(av, &mlx.map);
	parse_map_height(av, &mlx.map, &mlx.pixel);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	mlx.picture.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.picture.addr = mlx_get_data_addr(mlx.picture.img,
			&mlx.picture.bits_per_pixel, &mlx.picture.line_length,
			&mlx.picture.endian);
	isometric(&mlx.map);
	draw_line_h(&mlx.picture, &mlx.line, &mlx.map);
	draw_line_v(&mlx.picture, &mlx.line, &mlx.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.picture.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, close_window_esc, &mlx);
	mlx_hook(mlx.win, 17, 1l << 0, close_window_x, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
