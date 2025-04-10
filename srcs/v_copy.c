/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:21:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/07 17:23:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/fdf.h"

// void	draw_line_v(t_img *img, t_line *line, t_map *map)
// {
// 	int		column;

// 	column = 0;
// 	while (column < map->width) // && column >= 0)
// 	{
// 		preparing_params_draw_line_v(line, map);
// 		if (line->dy >= 0)
// 			bresenham_formula_v(line, img);
// 		column++;
// 	}
// }

// void	preparing_params_draw_line_v(t_line *line, t_map *map)
// {
// 	line->a.x = map->grid[0][0].x;
// 	line->a.y = map->grid[0][0].y;
// 	line->b.x = map->grid[map->height - 1][100].x;
// 	line->b.y = map->grid[map->height - 1][100].y;
// 	line->dx = abs(line->b.x - line->a.x);
// 	line->dy = abs(line->b.y - line->a.y);
// 	line->err = line->dx - line->dy;
// 	line->x_inc = 1;
// 	if (line->a.x >= line->b.x)
// 		line->x_inc = -1;
// 	line->y_inc = 1;
// 	if (line->a.y >= line->b.y)
// 		line->y_inc = -1;
// }

// void bresenham_formula_v(t_line *line, t_img *img)
// {
// 	int	x;
// 	int	y;
// 	int	e2;
// 	// float	row_step;
// 	// float	curr_row;
// 	// int		grid_row;

// 	// row_step = (float)(map->height - 1) / line->dx;
// 	// curr_row = 0;
// 	x = line->a.x;
// 	y = line->a.y;
// 	while (1)
// 	{
// 		// grid_row = (int)curr_row;
// 		// if (grid_row >= 0 && grid_row < map->height)
// 		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 			my_mlx_pixel_put(img, x, y, 0xFFFFFF);
// 		if (x == line->b.x && y == line->b.y)
// 			break ;
// 		e2 = 2 * line->err;
// 		if (e2 > -(line->dy))
// 		{
// 			line->err -= line->dy;
// 			x += line->x_inc;
// 		}
// 		if (e2 < line->dx)
// 		{
// 			line->err += line->dx;
// 			y += line->y_inc;
// 		}
// 		// curr_row += row_step;
// 	}
// }

// ____________________________________________
// the original Standard Bresenham Algorithm 
// void line(int x0, int y0, int x1, int y1) {
// 	int dx = abs(x1-x0);
// 	int dy = abs(y1-y0);
// 	int sx = x0<x1 ? 1 : -1;
// 	int sy = y0<y1 ? 1 : -1;
// 	int err = dx-dy;
	
// 	while(1) {
// 		setPixel(x0,y0);
// 		if (x0==x1 && y0==y1) break;
// 		int e2 = 2*err;
// 		if (e2 > -dy) { err -= dy; x0 += sx; }
// 		if (e2 < dx) { err += dx; y0 += sy; }
// 	}
// }


// void bresenham_formula_v(t_line *line, t_map *map, t_img *img, int column)
// {
// 	int	x;
// 	int	y;
// 	int	e2;

// 	x = line->a.x;
// 	y = line->a.y;
// 	while (1)
//     {
//         my_mlx_pixel_put(img, x, y, map->grid[0][column].colour);
//         if (x == line->b.x && y == line->b.y) break;
		
//         e2 = 2*line->err;
//         if (e2 > -(line->dy)) { line->err -= line->dy; x += line->x_inc; }
//         if (e2 < line->dx) { line->err += line->dx; y += line->y_inc; }
//     }
// }


// void bresenham_formula_v(t_line *line, t_map *map, t_img *img, int column)
// {
// 	int		p;
// 	float	row_step;
// 	float	curr_row;
// 	int		grid_row;

// 	p = 2 * line->dx - line->dy;
// 	row_step = (float)(map->height - 1) / line->dy;
// 	curr_row = 0;
// 	while (line->a.x <= line->b.x && line->a.y <= line->b.y)
// 	{
// 		grid_row = (int)curr_row;
// 		my_mlx_pixel_put(img, line->a.x, line->a.y,
// 			map->grid[grid_row][column].colour);
// 		if (p >= 0)
// 		{
// 			p = p + 2 * line->dx - 2 * line->dy;
// 			line->a.x++;
// 		}
// 		else
// 		{
// 			p = p + 2 * line->dx;
// 			line->a.y++;
// 		}
// 		curr_row += row_step;
// 	}
// }

// this one jadi all v and h

















// void draw_line_h(t_img *img) //, t_line *line) //, t_map *map)
// {
//     int i = 0;
//     while (i < 300) {
//         my_mlx_pixel_put(img, 100+i, 100, 0xFFFF0000); // Red
//         my_mlx_pixel_put(img, 100, 100+i, 0xFF00FF00); // Green
//         i++;
//     }
// }


// void	draw_line_h(t_img *img, t_line *line, t_map *map)
// {
// 	int	p;
// 	// int	row;
// 	int	column;

// 	column = 0;
// 	while (column < map->width && column >= 0)
// 	{
// 		preparing_params_draw_line_v(line, map, column);
// 		printf("column %d: (%d,%d) to (%d,%d)\n", column, line->a.x, line->y0, line->b.x, line->b.y);
// 		// printf("x0: %d\n", line->x0);
// 		// printf("y0: %d\n", line->y0);
// 		// printf("b.x: %d\n", line->x1);
// 		// printf("y1: %d\n", line->y1);

// 		if (line->dx != 0 && line->dx >= 0)
// 		{
// 			p = 2 * line->dy - line->dx;
// 			column = 0;
// 			while (column <= line->dx && column >= 0)
// 			{
// 				my_mlx_pixel_put(img, line->x0 + column, line->y0,
// 					0xFF00FF00);
// 				if (p >= 0)
// 				{
// 					line->y0 += line->dir;
// 					p = p - 2 * line->dx;
// 				}
// 				p = p + 2 * line->dy;
// 				column++;
// 			}
// 		}
// 		column++;
// 	}
// }

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