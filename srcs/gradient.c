/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:27:45 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/10 09:53:47 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	fraction(int start_axis, int end_axis, int curr_pixel_axis)
{
	int		distance;
	int		position;
	float	fraction_calc;

	distance = start_axis - end_axis;
	position = curr_pixel_axis - start_axis;
	fraction_calc = position / distance;
	return (fraction_calc);
}

static int	set_gradient(int *start, int *end, float *distance)
{
	int	red;
	int	green;
	int	blue;

	red = ((*start >> 16) & 0xFF) + *distance * (((*end >> 16) & 0xFF)
			- ((*start >> 16) & 0xFF));
	green = ((*start >> 8) & 0xFF) + *distance * (((*end >> 8) & 0xFF)
			- ((*start >> 8) & 0xFF));
	blue = (*start & 0xFF) + *distance * ((*end & 0xFF)
			- (*start & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

int	gradient(t_line *line, t_pixel *current) //, t_pixel *curr_pixel
{
	float	calc;
	int		colour;

	if (line->a.colour == line->b.colour)
		return (line->a.colour);
	if (abs(line->dx) > abs(line->dy))
		calc = fraction(line->a.x, line->b.x, current->x);
	else
		calc = fraction(line->a.y, line->b.y, current->y);
	colour = set_gradient(&line->a.colour, &line->b.colour, &calc);
	printf(" colour: %d\n", colour);
	return (colour);
}
