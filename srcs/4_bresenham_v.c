/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_bresenham_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:21:13 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/14 16:08:24 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_v(t_img *img, t_line *line, t_map *map)
{
	int	column;
	int	row;

	column = 0;
	while (column < map->width)
	{
		row = 0;
		while (row < map->height - 1)
		{
			prepare_params_v(line, map, column, row);
			bresenham(line, img);
			row++;
		}
		column++;
	}
}

void	prepare_params_v(t_line *line, t_map *map, int column, int row)
{
	line->a.x = map->grid[row][column].x;
	line->a.y = map->grid[row][column].y;
	line->a.colour = map->grid[row][column].colour;
	line->b.x = map->grid[row + 1][column].x;
	line->b.y = map->grid[row + 1][column].y;
	line->b.colour = map->grid[row + 1][column].colour;
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
