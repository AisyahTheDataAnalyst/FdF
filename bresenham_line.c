/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:06:43 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/31 10:42:35 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel_addr;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	pixel_addr = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel_addr = color;
}

static void	cal_bh_state(t_point p0, t_point p1, t_bh_state *state)
{
	state->dx = abs(p1.osx - p0.osx);
	state->dy = abs(p1.osy - p0.osy);
	if (state->dx > state->dy)
		state->points = state->dx;
	else
		state->points = state->dy;
	if (p0.osx < p1.osx)
		state->sx = 1;
	else
		state->sx = -1;
	if (p0.osy < p1.osy)
		state->sy = 1;
	else
		state->sy = -1;
	state->err = state->dx - state->dy;
}

int	gradient_color(int p0_color, int p1_color, int i, t_bh_state	*state)
{
	t_rgb	rgb;
	float	ratio;
	int		r;
	int		g;
	int		b;

	ratio = (float)i / state->points;
	rgb.start_r = (p0_color >> 16) & 0xFF;
	rgb.start_g = (p0_color >> 8) & 0xFF;
	rgb.start_b = p0_color & 0xFF;
	rgb.end_r = (p1_color >> 16) & 0xFF;
	rgb.end_g = (p1_color >> 8) & 0xFF;
	rgb.end_b = p1_color & 0xFF;
	r = rgb.start_r + (int)((rgb.end_r - rgb.start_r) * ratio);
	g = rgb.start_g + (int)((rgb.end_g - rgb.start_g) * ratio);
	b = rgb.start_b + (int)((rgb.end_b - rgb.start_b) * ratio);
	return ((r << 16) | (g << 8) | b);
}

static void	renew_error(t_bh_state *state, t_point *p0)
{
	int	e2;

	e2 = 2 * state->err;
	if (e2 > -state->dy)
	{
		state->err -= state->dy;
		p0->osx += state->sx;
	}
	if (e2 < state->dx)
	{
		state->err += state->dx;
		p0->osy += state->sy;
	}
}

void	brehensam_line(t_data *data, t_point p0, t_point p1)
{
	t_bh_state	state;
	int			i;
	int			color;

	cal_bh_state(p0, p1, &state);
	i = 0;
	color = p0.color;
	while (1)
	{
		if (p0.color != p1.color)
			color = gradient_color(p0.color, p1.color, i, &state);
		my_pixel_put(data, p0.osx, p0.osy, color);
		if (p0.osx == p1.osx && p0.osy == p1.osy)
			break ;
		renew_error(&state, &p0);
		i++;
	}
}
