/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:42:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/09 18:14:14 by aimokhta         ###   ########.fr       */
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
	t_mlx	mlx;

	(void)ac;
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
	draw_line_h(&mlx.picture, &mlx.line, &mlx.map); //, &mlx.pixel);
	draw_line_v(&mlx.picture, &mlx.line, &mlx.map); //, &mlx.pixel);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.picture.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, close_window_esc, &mlx);
	mlx_hook(mlx.win, 17, 1l << 0, close_window_x, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}


// ________________________test_______________________________
// int	main(int ac, char **av)
// {
// 	t_mlx	mlx;

// 	fdf_init(&mlx);
// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
// 	mlx.picture.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
// 	mlx.picture.addr = mlx_get_data_addr(mlx.picture.img,
// 		&mlx.picture.bits_per_pixel, &mlx.picture.line_length,
// 		&mlx.picture.endian);

// 	if (ac == 2)
// 	{
// 		counting_height_width(av, &mlx.map);
// 		parse_map_height(av, &mlx.map, &mlx.pixel);

// 		// isometric conversion and map drawing
// 		// (Uncomment if you want to test the map)
// 		// draw_line_h(&mlx.picture, &mlx.line, &mlx.map);
// 		// draw_line_v(&mlx.picture, &mlx.line, &mlx.map);
// 	}
// 	else
// 	{
// 		// No file = test mode
// 		test_all_octants(&mlx.line, &mlx.picture);
// 	}

// 	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.picture.img, 0, 0);
// 	mlx_hook(mlx.win, 2, 1L << 0, close_window_esc, &mlx);
// 	mlx_hook(mlx.win, 17, 1L << 0, close_window_x, &mlx);
// 	mlx_loop(mlx.mlx);
// 	return (0);
// }
