/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:42:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/29 16:38:21 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int	main(int ac, char **av)
// {
// 	t_map	map;

// 	if (ac != 2)
// 		exit(1);
// 	ft_bzero(&map, sizeof(t_map));
// 	counting_height_width(av, &map);
// 	parse_map_height(av, &map);
// 	printf("Numbers of height: %d\n", map.height);
// 	printf("Numbers of width: %d\n", map.width);
// 	printf("Number of x for pixel[2][3]: %d\n", map.grid[2][3].x);
// 	printf("Number of y for pixel[2][3]: %d\n", map.grid[2][3].y);
// 	printf("Number of z for pixel[2][3]: %d\n", map.grid[2][3].z);
// 	printf("Number of colour for pixel[2][3]: %d\n", map.grid[2][3].colour);
// 	free_map(&map);
// 	return (0);
// }

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
	// t_img	img;
	t_mlx	mlx;
	t_line	line;
	// t_map	map;

	if (ac != 2)
		exit(1);
	// printf("here\n");
	fdf_init(&mlx);
	counting_height_width(av, &mlx.mapping);
	parse_map_height(av, &mlx.mapping);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Welcome to aimokhta's FdF!");
	mlx.picture.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.picture.addr = mlx_get_data_addr(mlx.picture.img, &mlx.picture.bits_per_pixel, &mlx.picture.line_length,
			&mlx.picture.endian);
	my_mlx_pixel_put(&mlx.picture, 1920/2, 1080/2, 0x00FF0000);
	draw_line_h(&mlx.picture, &line, &mlx.mapping, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.picture.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, close_window_esc, &mlx);
	mlx_hook(mlx.win, 17, 1l << 0, close_window_x, &mlx);
	mlx_loop(mlx.mlx);
	// cleanup(&mlx);
	return (0);
}
