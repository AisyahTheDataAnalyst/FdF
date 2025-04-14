/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_bresenham_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:14:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/14 16:08:15 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_h(t_img *img, t_line *line, t_map *map)
{
	int	row;
	int	column;

	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (column < map->width - 1)
		{
			prepare_params_h(line, map, row, column);
			bresenham(line, img);
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

void	bresenham(t_line *line, t_img *img)
{
	int		colour;
	t_pixel	current;

	current = line->a;
	while (current.x != line->b.x || current.y != line->b.y)
	{
		colour = gradient(line, &current);
		if (current.x >= 0 && current.x < WIN_WIDTH
			&& current.y >= 0 && current.y < WIN_HEIGHT)
			my_mlx_pixel_put(img, current.x, current.y, colour);
		bresenham_formula(line, &current.x, &current.y);
	}
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
