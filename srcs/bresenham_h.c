/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:14:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/09 20:59:21 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_h(t_img *img, t_line *line, t_map *map) //, t_pixel *pixel)
{
	int	row;
	int	column;

	row = 0;
	while (row < map->height) // && row >= 0)
	{
		column = 0;
		while (column < map->width - 1)
		{
			prepare_params_h(line, map, row, column);
			if (line->dx >= 0) //(line->dx >= line->dy) //
				bresenham(line, img); //, pixel);
			else
				bresenham_formula_general(line, map, img); //, pixel);
			column++;
		}
		row++;
	}
}

void	prepare_params_h(t_line *line, t_map *map, int row, int column)
{
	line->a.x = map->grid[row][column].x;
	line->a.y = map->grid[row][column].y;
	line->a.colour = map->grid[row][column].colour;
	line->b.x = map->grid[row][column + 1].x;
	line->b.y = map->grid[row][column + 1].y;
	line->b.colour = map->grid[row][column + 1].colour;
	line->dx = abs(line->b.x - line->a.x);
	line->dy = abs(line->b.y - line->a.y);
	line->err = line->dx - line->dy;
	line->x_inc = 1;
	if (line->a.x >= line->b.x)
		line->x_inc = -1;
	line->y_inc = 1;
	if (line->a.y >= line->b.y)
		line->y_inc = -1;
}

// ORIGINAL
void bresenham(t_line *line, t_img *img) //, t_pixel *pixel)
{
	int		colour;
	t_pixel	current;

	current = line->a;
	while (current.x != line->b.x || current.y != line->b.y)
	{
		colour = gradient(line, &current); //, pixel);
		if (current.x >= 0 && current.x < WIN_WIDTH
			&& current.y >= 0 && current.y < WIN_HEIGHT)
			my_mlx_pixel_put(img, current.x, current.y, colour);
		bresenham_formula(line, &current.x, &current.y);
	}
	// my_mlx_pixel_put(img, line->b.x, line->b.y, line->b.colour);
}

int	ft_max(int value_a, int value_b)
{
	if (value_a > value_b)
		return (value_a);
	return (value_b);
}

void	bresenham_formula(t_line *line, int *x, int *y)
{
	int	e2;

	e2 = 2 * line->err;
	if (e2 > -line->dy)
	{
		line->err -= line->dy;
		*x += line->x_inc;
	}
	if (e2 < line->dx)
	{
		line->err += line->dx;
		*y += line->y_inc;
	}
}

void	bresenham_formula_general(t_line *line, t_map *map, t_img *img) //, t_pixel *pixel)
{
	int	e2;
	int		colour;
	t_pixel	current;

	current = line->a;

	while (current.x != line->b.x || current.y != line->b.y)
	{
		colour = gradient(line, &current); //, pixel);
		if (current.x >= 0 && current.x < map->width && current.y >= 0 && current.y < map->height)
			my_mlx_pixel_put(img, current.x, current.y, colour);
		if (current.x == line->b.x && current.y == line->b.y)
			break ;
		e2 = 2 * line->err;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			current.x += line->x_inc;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			current.y += line->y_inc;
		}
	}
	my_mlx_pixel_put(img, line->b.x, line->b.y, line->b.colour);
}

// BACKUUUUUUUPPPPPPPPPPPP
// void	bresenham_formula_general(t_line *line, t_map *map, t_img *img) //, t_pixel *pixel)
// {
// 	int	x;
// 	int	y;
// 	int	e2;
// 	int		colour;

// 	x = line->a.x;
// 	y = line->a.y;

// 	while (1)
// 	{
// 		colour = gradient(line); //, pixel);
// 		if (x >= 0 && x < map->width && y >= 0 && y < map->height)
// 			my_mlx_pixel_put(img, x, y, 0xFFFFFF);
// 		if (x == line->b.x && y == line->b.y)
// 			break ;
// 		e2 = 2 * line->err;
// 		if (e2 > -line->dy)
// 		{
// 			line->err -= line->dy;
// 			x += line->x_inc;
// 		}
// 		if (e2 < line->dx)
// 		{
// 			line->err += line->dx;
// 			y += line->y_inc;
// 		}
// 	}
// }

// BACKUPPPPPPPPPPPPPPPPPPPPP
// void	prepare_params_h(t_line *line, t_map *map, int row, int column)
// {
// 	line->a.x = map->grid[row][column].x;
// 	line->a.y = map->grid[row][column].y;
// 	line->b.x = map->grid[row][column + 1].x;
// 	line->b.y = map->grid[row][column + 1].y;
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

// // ORIGINAL BACKUPPPPPPPPPPPPPPPP
// void bresenham(t_line *line, t_img *img) //, t_pixel *pixel)
// {
// 	int		x;
// 	int		y;
// 	int		colour;

// 	x = line->a.x;
// 	y = line->a.y;
// 	while (1)
// 	{
// 		colour = gradient(line); //, pixel);
// 		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 			my_mlx_pixel_put(img, x, y, colour);
// 		if (x == line->b.x && y == line->b.y)
// 			break ;
// 		bresenham_formula(line, &x, &y);
// 	}
// }


















































// void	bresenham_formula_general(t_line *line, t_map *map, t_img *img)
// {
// 	int	x;
// 	int	y;
// 	int	e2;

// 	x = line->a.x;
// 	y = line->a.y;
// 	while (1)
// 	{
// 		if (x >= 0 && x < map->width && y >= 0 && y < map->height)
// 			my_mlx_pixel_put(img, x, y, map->grid[y][x].colour);
// 		if (x == line->b.x && y == line->b.y)
// 			break ;
// 		e2 = 2 * line->err;
// 		if (e2 > -line->dy)
// 		{
// 			line->err -= line->dy;
// 			x += line->x_inc;
// 		}
// 		if (e2 < line->dx)
// 		{
// 			line->err += line->dx;
// 			y += line->y_inc;
// 		}
// 	}
// }


// void	bresenham_formula_h(t_line *line, t_map *map, t_img *img, int row)
// {
// 	int		x;
// 	int		y;
// 	int		grid_column;

// 	// Start at the beginning of the line
// 	x = line->a.x;
// 	y = line->a.y;

// 	// Loop through all points in the line
// 	while (1)
// 	{
// 		// Ensure that we're within bounds of the window and grid
// 		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 		{
// 			// Get the column of the grid based on the x-coordinate
// 			grid_column = (int)((x - line->a.x) * (float)(map->width - 1) / line->dx);

// 			// Ensure the column is valid
// 			if (grid_column >= 0 && grid_column < map->width)
// 			{
// 				// Set the pixel color at (x, y)
// 				my_mlx_pixel_put(img, x, y, map->grid[row][grid_column].colour);
// 			}
// 		}

// 		// Check if we've reached the endpoint
// 		if (x == line->b.x && y == line->b.y)
// 			break;

// 		// Move to the next point along the line using Bresenham's formula
// 		bresenham_formula(line, &x, &y);
// 	}
// }


// not x and y, that means you want to modify the pointer itself
// we want to modify the value of the pointer is pointing to










// donno if work or not
// void bresenham_formula_h(t_line *line, t_map *map, t_img *img, int row)
// {
//     int x = line->a.x;
//     int y = line->a.y;
//     int err = line->err;
//     float column_step;
//     float curr_column = 0;
//     int grid_column;
// 	int e2;

//     if (line->dx == 0)
//         column_step = 0;
//     else
//         column_step = (float)(map->width - 1) / (float)line->dx;

//     // Start drawing horizontal line
//     while (1)
//     {
//         grid_column = (int)curr_column;

//         // Make sure the column is within bounds
//         if (grid_column >= 0 && grid_column < map->width)
//         {
//             if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
//             {
//                 my_mlx_pixel_put(img, x, y, map->grid[row][grid_column].colour);
//             }
//         }

//         // If we reached the destination point, break the loop
//         if (x == line->b.x && y == line->b.y)
//             break;

//         e2 = 2 * err;

//         // Check and update x-coordinate
//         if (e2 > -line->dy)
//         {
//             err -= line->dy;
//             x += line->x_inc;
//             curr_column += column_step; // Increment column for horizontal movement
//         }

//         // Check and update y-coordinate
//         if (e2 < line->dx)
//         {
//             err += line->dx;
//             y += line->y_inc;
//         }
//     }
// }










// second original
// void bresenham_formula_h(t_line *line, t_map *map, t_img *img, int row)
// {
// 	int x = line->a.x;
// 	int y = line->a.y;
// 	int line->err = line->err;
// 	float column_step;
// 	float curr_column = 0;
// 	int grid_column;

// 	if (line->dx == 0)
// 		column_step = 0;
// 	else
// 		column_step = (float)(map->width - 1) / (float)line->dx;

// 	while (1)
// 	{
// 		grid_column = (int)curr_column;

// 		// Make sure we’re not out of bounds before drawing
// 		if (grid_column >= 0 && grid_column < map->width)
// 		{
// 			if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 				my_mlx_pixel_put(img, x, y, map->grid[row][grid_column].colour);
// 		}

// 		// Stop condition
// 		if (x == line->b.x && y == line->b.y)
// 			break;

// 		int e2 = 2 * err;

// 		if (e2 > -line->dy)
// 		{
// 			err -= line->dy;
// 			x += line->x_inc;
// 			curr_column += column_step;
// 		}
// 		if (e2 < line->dx)
// 		{
// 			err += line->dx;
// 			y += line->y_inc;
// 		}
// 	}
// }












































// // this one jadi all v and h
// void bresenham_formula_h(t_line *line, t_map *map, t_img *img, int row)
// {
// 	int	x;
// 	int	y;
// 	int	e2;

// 	x = line->a.x;
// 	y = line->a.y;
// 	while (1)
// 	{
// 		if (x >= 0 && x < map->width && y >= 0 && y < map->height)
// 			my_mlx_pixel_put(img, x, y, map->grid[row][0].colour);
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
// 	}
// }

// void	bresenham_formula_h(t_line *line, t_map *map, t_img *img, int row)
// {
// 	int		p;
// 	float	column_step;
// 	float	curr_column;
// 	int		grid_column;

// 	p = 2 * line->dy - line->dx;
// 	column_step = (float)(map->width - 1) / line->dx;
// 	curr_column = 0;
// 	while (line->a.x <= line->b.x && line->a.y <= line->b.y)
// 	{
// 		grid_column = (int)curr_column;
// 		my_mlx_pixel_put(img, line->a.x, line->a.y,
// 			map->grid[row][grid_column].colour);
// 		if (p >= 0)
// 		{
// 			p = p + 2 * line->dy - 2 * line->dx;
// 			line->a.y++;
// 		}
// 		else
// 		{
// 			p = p + 2 * line->dy;
// 			line->a.x++;
// 		}
// 		curr_column += column_step;
// 	}
// }