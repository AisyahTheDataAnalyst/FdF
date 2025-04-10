/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_gradient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:27:45 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/10 16:30:49 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	fraction(int s, int e, int curr)
{
	int		distance;
	int		position;
	float	calc;

	position = curr - s;
	distance = e - s;
	calc = (float)position / (float)distance;
	return (calc);
}

static int	set_gradient(int *s, int *e, float *distance)
{
	int	r;
	int	g;
	int	b;

	r = ((*s >> 16) & 0xFF) + (int)(*distance * (((*e >> 16) & 0xFF)
				- ((*s >> 16) & 0xFF)));
	g = ((*s >> 8) & 0xFF) + (int)(*distance * (((*e >> 8) & 0xFF)
				- ((*s >> 8) & 0xFF)));
	b = (*s & 0xFF) + (int)(*distance * ((*e & 0xFF) - (*s & 0xFF)));
	return ((r << 16) | (g << 8) | b);
}

int	gradient(t_line *line, t_pixel *current)
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
	return (colour);
}
