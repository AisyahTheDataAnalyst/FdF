/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:00:25 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/21 12:14:53 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>

// //EVENT
// // - what you do (moving/clicking the mouse, press a key on keyboard, closing a window)
// // - events are actions happen while your program is running
// //HOOK
// // - effect after you do event (42 map becoming more higher or lower)
// // - "hey when this event happen, call this function"
// // SUMMARY OF THE CODE:
// // - mlx_init() : initializes MiniLibX
// // - mlx_new_window : creates new window
// // - mlx_key_hook : sets up a fn to handle key presses
// // - mlx_mouse_hook : sets up a fn to handle mouse clicks
// // - mlx_hook : sets up function to handles more advanced events, like window resizing/closing
// // - mlx_loop : keep program running and listening for events / start the event loop

// typedef struct s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// // quite windows using esc button
// int	close(int keycode, t_vars *vars)
// {
// 	(void)keycode;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	printf("Window closed\n");
// 	return (0);
// }

// //close: The function to call when the event occurs (in this case, the close function).
// // &vars: A pointer to the t_vars struct, which is passed to the close function as the vars parameter.
// // vars.win: The window to listen for events on.
// // 2: The event type (2 corresponds to KeyPress in the X11 Events table).
// // 1L<<0 corresponds to KeyPressMask, which means "listen for any key press."
// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "You can do this Aisyah");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }


// -----------------------------------------------------------------------------------

// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h> // For time() in handle_key_repeat

// #define ESC_KEY 65307
// #define MOUSE_ENTER 1
// #define MOUSE_LEAVE 2

// int close_window(void *mlx_ptr, void *win_ptr)
// {
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     exit(0);
// }

// int handle_keypress(int keycode, void *mlx_ptr, void *win_ptr)
// {
//     if (keycode == ESC_KEY)
//         close_window(mlx_ptr, win_ptr);
//     return (0);
// }

// int handle_resize(int width, int height, void *mlx_ptr)
// {
// 	(void)mlx_ptr;
//     printf("Window resized to %dx%d\n", width, height);
//     return (0);
// }

// int handle_mouse(int mousecode, void *mlx_ptr)
// {
// 	(void)mlx_ptr;
//     if (mousecode == MOUSE_ENTER)
//         printf("Hello!\n");
//     else if (mousecode == MOUSE_LEAVE)
//         printf("Bye!\n");
//     return (0);
// }

// int handle_key_repeat(int keycode, void *mlx_ptr)
// {
//     (void)mlx_ptr;
// 	(void)keycode;
// 	static time_t start_time = 0;
//     time_t current_time = time(NULL);

//     if (start_time == 0)
//         start_time = current_time;

//     if (current_time - start_time > 2) // 2 seconds
//     {
//         printf("Key held for more than 2 seconds\n");
//         start_time = 0;
//     }
//     return (0);
// }

// int main(void)
// {
//     void *mlx_ptr;
//     void *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 800, 600, "MiniLibX Window");

//     // Set up hooks
//     mlx_hook(win_ptr, 2, 1L<<0, handle_keypress, mlx_ptr);
//     mlx_hook(win_ptr, 17, 1L<<17, close_window, mlx_ptr);
//     mlx_hook(win_ptr, 6, 1L<<6, handle_mouse, mlx_ptr);
//     mlx_hook(win_ptr, 3, 1L<<1, handle_key_repeat, mlx_ptr);
//     mlx_hook(win_ptr, 22, 1L<<22, handle_resize, mlx_ptr);

//     // Loop to keep the window open
//     mlx_loop(mlx_ptr);

//     return (0);
// }
