/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:42:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/27 16:04:30 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int	main(int ac, char **av)
// {
// 	t_map	map;

// 	if (ac != 2)
// 		exit(1);
// 	ft_bzero(&map, sizeof(t_map));
// 	counting_row_col(av, &map);
// 	parse_map_row(av, &map);
// 	printf("Numbers of row: %d\n", map.row);
// 	printf("Numbers of column: %d\n", map.column);
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
// // mlx_get_data_addr 
// // 	- creating an image addr 
// //   - after creating an image, we pass all the referenced ones 
// //   - to be set accordingly for the current data address 
// // my_mlx_pixel_put 
// // 	- putting 1 pixel only into the image 
// //   - with starting x starting y and color
// // mlx_put_image_to_window
// // 	- as the name stated
// // mlx_loop
// // 	- open windows until we cntrlD at the terminal  
// //   - initiate window rendering
int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Welcome to aimokhta's FdF! :)");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 1920/2, 1080/2, 0x00FF0000); // just a pixel
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, close_window, &img);
	mlx_loop(img.mlx);
}
