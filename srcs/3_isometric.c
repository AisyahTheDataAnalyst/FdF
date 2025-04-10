/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_isometric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:17:08 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/10 17:41:53 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	isometric_projection(t_pixel *p)
{
	float	x;
	float	y;
	float	z;

	x = p->ori_x * ISO_SCALE;
	y = p->ori_y * ISO_SCALE;
	z = p->ori_z * Z_SCALE;
	p->x = (int)((x - y) * cos(ISO_ANGLE));
	p->y = (int)(((x + y) * sin(ISO_ANGLE) / COMPRESSION - z));
	p->x += WIN_WIDTH / 2;
	p->y += WIN_HEIGHT / 4;
}

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
			isometric_projection(&map->grid[i][j]);
			j++;
		}
		i++;
	}
}
