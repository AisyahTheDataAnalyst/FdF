/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:21:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/29 16:41:30 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_h(t_img *img, t_line *line, t_map *map, unsigned int colour)
{
	int	p;
	int	i;

	preparing_params_draw_line(line, map);
	printf("x0: %d\n", line->x0);
	printf("x1: %d\n", line->x1);
	printf("y0: %d\n", line->y0);
	printf("y1: %d\n", line->y1);


	if (line->dx != 0)
	{
		p = 2 * line->dy - line->dx;
		i = 0;
		while (i <= line->dx)
		{
			my_mlx_pixel_put(img, line->x0 + i, line->y0, colour);
			if (p >= 0)
			{
				line->y0 += line->dir;
				p -= 2 * line->dx;
			}
			p += 2 * line->dy;
			i++;
		}
	}
}

void	preparing_params_draw_line(t_line *line, t_map *map)
{
	line->x0 = map->grid[0][0].x;
	line->x1 = map->grid[100][100].x;
	line->y0 = map->grid[0][0].y;
	line->y1 = map->grid[100][100].y;
	line->dx = line->x1 - line->x0;
	line->dy = line->y1 - line->y0;
	if (line->dy < 0)
	{
		line->dir = -1;
		line->dy = -(line->dy);
	}
	else
		line->dir = 1;
}



// void	draw_line(t_img *img, t_line *line, t_map *map, unsigned int colour)
// {
// 	int	x;
// 	int	y;
// 	int	D;

// 	x = 0;
// 	y = 0;
// 	line->dx = abs(map->height - 1][map->width - 1] - x);
// 	line->dy = abs(line->end.y - y);
// 	point = 2 * line->dy - line->dx;
// 	while (x <= map->width)
// 	{
// 		my_mlx_pixel_put(img, x, y, colour);
// 		x++;
// 		if (point < 0)
// 			point = point + 2 * line->dy;
// 		else
// 		{
// 			point = point + 2 * line->dy - 2 * line->dx;
// 			y++;
// 		}
// 	}
// }


// def draw_line_h (x0, y0, x1, y1)
// 	if x0 > x1:
// 		x0,x1 = x1,x0
// 		y0,y1 = y1,y0

// 	dx = x1 - x0
// 	dy = y1 - y0

// 	dir = -1 if dy < 0 else 1
// 	dy *= dir

// 	if dx != 0:
// 		y = y0;
// 		p = 2*dy - dx
// 		for i in range(dx+1):
// 			putPixel(x0 + i, y)
// 			if p >= 0:
// 				y += dir
// 				p = p - 2*dx
// 			p = p + 2*dy


// void	draw_line_h(t_img *img, t_line *line, t_map *map, unsigned int colour)
// {
// 	int	D;

// 	line->x0 = map->grid[0][0].x;
// 	line->y0 = map->grid[0][0].y;
// 	line->x1 = map->grid[0][map->width - 1].x;
// 	line->y1 = map->grid[0][map->width - 1].y;
// 	line->dx = line->x1 - line->x0;
// 	line->dy = line->y1 - line->y0;
// 	D = 2 * line->dy - line->dx;
// 	while (line->x0 <= map->width - 1)
// 	{
// 		my_mlx_pixel_put(img, line->x0, line->y0, colour);
// 		line->x0++;
// 		if (D < 0)
// 			D = D + 2 * line->dy;
// 		else
// 		{
// 			D = D + 2 * line->dy - 2 * line->dx;
// 			line->y0++;
// 		}
// 	}
// }