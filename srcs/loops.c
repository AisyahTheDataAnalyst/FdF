/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:23:28 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/21 14:47:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // 2 FN ONLY : 
// // mlx_loop && mlx_loop_hook;

// #include <mlx.h>
// #include <stdlib.h>

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// // Function to draw a pixel on the image
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// // Function to handle rendering for each frame
// int	render_next_frame(void *param)
// {
// 	static int	x = 0;
// 	t_data		*data;
// 	void		*mlx;
// 	void		*mlx_win;

// 	// Cast param to access mlx and mlx_win
// 	void		**params = (void **)param;
// 	mlx = params[0];
// 	mlx_win = params[1];
// 	data = (t_data *)params[2];

// 	// Clear the screen by filling it with black
// 	for (int y = 0; y < 1080; y++)
// 		for (int x = 0; x < 1920; x++)
// 			my_mlx_pixel_put(data, x, y, 0x00000000);

// 	// Draw a moving red pixel
// 	my_mlx_pixel_put(data, x, 540, 0x00FF0000);

// 	// Update the x position for animation
// 	x++;
// 	if (x >= 1920)
// 		x = 0;

// 	// Display the updated image in the window
// 	mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);

// 	return (0);
// }

// // Function to handle keypress events (e.g., ESC key)
// int	handle_keypress(int keycode, void *param)
// {
// 	void	**params = (void **)param;
// 	void	*mlx = params[0];
// 	void	*mlx_win = params[1];

// 	if (keycode == 65307) // ESC key
// 	{
// 		mlx_destroy_window(mlx, mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	void	*params[3]; // Array to store mlx, mlx_win, and img

// 	// Initialize MiniLibX
// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1); // Error handling

// 	// Create a new window
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	if (!mlx_win)
// 		return (1); // Error handling

// 	// Create a new image
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	if (!img.img)
// 		return (1); // Error handling

// 	// Get the image's memory address and properties
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

// 	// Store mlx, mlx_win, and img in the params array
// 	params[0] = mlx;
// 	params[1] = mlx_win;
// 	params[2] = &img;

// 	// Set up the render loop
// 	mlx_loop_hook(mlx, render_next_frame, params);

// 	// Set up keypress event hook
// 	mlx_hook(mlx_win, 2, 1L<<0, handle_keypress, params);

// 	// Set up window close event hook (red cross button)
// 	mlx_hook(mlx_win, 17, 1L<<17, (int (*)())exit, 0);

// 	// Start the MiniLibX event loop
// 	mlx_loop(mlx);

// 	return (0);
// }