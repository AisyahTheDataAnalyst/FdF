/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:17:08 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/09 10:29:35 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("before: grid[%d][%d]: x=[%d] | y=[%d] | z=[%d]\n", i, j, map->grid[i][j].x, map->grid[i][j].y, map->grid[i][j].z);
			isometric_projection(&map->grid[i][j]); // ,&mlx.map.grid[i][j].x, &mlx.map.grid[i][j].y, &mlx.map.grid[i][j].z); , &mlx.map);		
			printf("after: grid[%d][%d]: x=[%d] | y=[%d] | z=[%d]\n", i, j, map->grid[i][j].x, map->grid[i][j].y, map->grid[i][j].z);
			j++;
		}
		i++;
	}	
}

// ORIGINALLLLLLL
void	isometric_projection(t_pixel *p)
{
	float	x;
	float	y;
	float	z;

	x = p->ori_x * ISO_SCALE;
	y = p->ori_y * ISO_SCALE;
	z = p->ori_z * ISO_SCALE;

	p->x = (int)((x - y) * cos(ISO_ANGLE));
	p->y = (int)(((x + y) * sin(ISO_ANGLE) / COMPRESSION - z));
	p->x += WIN_WIDTH / 2;
	p->y += WIN_HEIGHT / 4;
	printf("p->z: %d\n", p->z);
}





// float & double is used for decimal
// float - 4 bytes, 7 digits
// double - 8 bytes, 15-16 digits
// void	isometric(t_pixel *pixel)
// {
// 	int 	tempx;
// 	int		tempy;
// 	double	angle;

// 	tempx = pixel->x;
// 	tempy = pixel->y;
// 	angle = M_PI / 6;
// 	pixel->x = (tempx - tempy) * cos(angle);
// 	pixel->y = (tempx + tempy) * sin(angle) - pixel->z;
// }

// void	center_and_scale(t_pixel *pixel, t_map *map)
// {
// 	pixel->x = (pixel->x - map->width / 2) * TILE_SIZE;
// 	pixel->y = (pixel->y - map->height / 2) * TILE_SIZE;

// }

//latest
// void	isometric(t_pixel *p)
// {
// 	float	prev_x;
// 	float	prev_y;

// 	// Save original coordinates before transforming
// 	prev_x = p->ori_x;
// 	prev_y = p->ori_y;

// 	// TRUE isometric projection (30°)
// 	p->x = (prev_x - prev_y) * ISO_SCALE;
// 	p->y = (prev_x + prev_y) * ISO_SCALE / 2 - p->z * Z_SCALE;

// 	// Center on screen
// 	p->x += WIN_WIDTH / 2;
// 	p->y += WIN_HEIGHT / 4;  // Divided by 4 for better centering
// 	// printf("Transformed: (%d,%d,%d) -> (%d,%d)\n", 
//     //    p->ori_x, p->ori_y, p->z, p->x, p->y);
// }

// void calculate_view_params(t_map *map)
// {
//     int max_z = 0;
// 	int min_z = 0;
// 	int	y = 0;
// 	int x;

// 	while (y < map->height)
//     {
//         x = 0;
//         while (x < map->width)
//         {
//             if (map->grid[y][x].z > max_z)
//                 max_z = map->grid[y][x].z;
//             if (map->grid[y][x].z < min_z)
//                 min_z = map->grid[y][x].z;
//             x++;
//         }
//         y++;
//     }
	
// 	// Calculate maximum expected coordinates
//     // float max_x = (map->width - 1) * ISO_SCALE;
//     // float max_y = (map->height - 1) * ISO_SCALE;
	
//     // Automatic centering
//     map->center_x = WIN_WIDTH / 2.0f;
//     map->center_y = WIN_HEIGHT / 2.0f + (map->height * ISO_SCALE * 0.4f);  // 0.4 gives better framing than 0.5
//     map->z_offset = (max_z - min_z) * Z_SCALE * 0.5f;         // Adjust for height range
// }

// void isometric(t_pixel *p, t_map *map)
// {
//     // Pure isometric projection (no artificial compression)
//     float iso_x = (p->ori_x - p->ori_y) * ISO_SCALE;
//     float iso_y = (p->ori_x + p->ori_y) * ISO_SCALE;
	
//     // Apply height and centering
//     p->x = iso_x + map->center_x;
//     p->y = iso_y - (p->z * Z_SCALE) + map->center_y - map->z_offset;
// }



// THISSSSSSSSSSSSS
// void isometric(t_pixel *p) //, t_map *map)
// {
// // 	// In your main setup code:
// // 	// float map_max_x = (map->width - 1) * ISO_SCALE;
// // 	// float map_max_y = (map->height - 1) * ISO_SCALE;
// // 	// float map_min_z = /* your minimum Z value */;
// // 	// float map_max_z = /* your maximum Z value */;

// // 	// Calculate automatic centering
// // 	// int win_center_x = WIN_WIDTH/2;
// // 	// int win_center_y = WIN_HEIGHT / 2 + ((map->height - 1) * ISO_SCALE) / 2;
// // 	// map_height_compensation = map_max_z * Z_SCALE * 0.5;
//     float x = p->ori_x - p->ori_y;
//     float y = p->ori_x + p->ori_y;
	
//     p->x =(int)(x * cos(ISO_ANGLE) * ISO_SCALE);  // Simple isometric X
//     p->y =(int)(y * sin(ISO_ANGLE) * ISO_SCALE / 2 - p->z * Z_SCALE);  // Simple isometric Y & add height effect              // Add height effect
	
//     // Center on screen
//     p->x += WIN_WIDTH / 2;
//     p->y += WIN_HEIGHT / 4;
// }



// this works FINALLY!!!
// ori_x/y must times with ISO_SCALE first
// sin(ISO_ANGLE) / (here) : here to control the compression
// void isometric(t_pixel *p)
// {
// 	float	x;
// 	float	y;

// 	x = p->ori_x * ISO_SCALE;
// 	y = p->ori_y * ISO_SCALE;
// 	p->x = (int)((x - y) * cos(ISO_ANGLE));
// 	p->y = (int)((x + y) * sin(ISO_ANGLE) / 1.8 - p->z * Z_SCALE);
// 	p->x += WIN_WIDTH / 2;
// 	p->y += WIN_HEIGHT / 4;
// 	printf("ori_x: %d, ori_y: %d, x: %.2f, y: %.2f, p->x: %d, p->y: %d\n", 
// 		p->ori_x, p->ori_y, x, y, p->x, p->y);
	
// }

// testing using pointer (THISSS)
// void isometric(t_pixel *p, int *x, int *y, int *z)
// {
// 	float var_x;
// 	float var_y;
// 	float	var_z;

// 	var_x = p->ori_x * ISO_SCALE;
// 	var_y = p->ori_y * ISO_SCALE;
// 	var_z = *z * ISO_SCALE;

// 	*x = (int)((var_x - var_y) * cos(ISO_ANGLE));
// 	*y = (int)((var_x + var_y) * sin(ISO_ANGLE) - var_z);
// 	*x += WIN_WIDTH / 2;
// 	*y += WIN_HEIGHT / 4;
// 	// printf("p->z: %d\n", p->z);
// }








// iso_x = ; // Isometric X (adjust scaling)
// iso_y =  / 1.5; // Isometric Y (adjust scaling)
// p->x = (int)((x - y) * cos(ISO_ANGLE) + WIN_WIDTH / 2); // Center the X position on the screen
// p->y = (int)(((x + y) * sin(ISO_ANGLE) - p->z * ISO_SCALE) + WIN_HEIGHT / 4); // Apply Z to Y and center vertically



// this one gets all the lines 
// void isometric(t_pixel *p)
// {
//     int orig_x = p->ori_x;
//     int orig_y = p->ori_y;
	
//     p->x = (orig_x - orig_y) * 20;  // Simple isometric X
//     p->y = (orig_x + orig_y) * 10;  // Simple isometric Y
//     p->y -= p->z * 5;               // Add height effect
	
//     // Center on screen
//     p->x += WIN_WIDTH / 2;
//     p->y += WIN_HEIGHT / 2;
// }

// void isometric(t_pixel *p)
// {
//     float x = p->ori_x;
//     float y = p->ori_y;
//     float z = p->z;  // MAKE SURE THIS IS YOUR PARSED Z-VALUE
	
//     // Isometric projection with height
//     p->x = (x - y) * 30;          // X position
//     p->y = (x + y) * 15 - z * 10; // Y position with height (z * 10 for visibility)
	
//     // Center on screen
//     p->x += WIN_WIDTH / 2;
//     p->y += WIN_HEIGHT / 2;
// }

// --------RESET-------
// void	reset_projection(t_map *map)
// {
// 	for (int i = 0; i < map->height; i++)
// 	{
// 		for (int j = 0; j < map->width; j++)
// 		{
// 			map->grid[i][j].x = map->grid[i][j].ori_x;
// 			map->grid[i][j].y = map->grid[i][j].ori_y;
// 			map->grid[i][j].z = map->grid[i][j].ori_z;
// 		}
// 	}
// }