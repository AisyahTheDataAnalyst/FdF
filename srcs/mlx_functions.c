/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:11:02 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/29 13:48:07 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_init(t_mlx *mlx)
{
	// ft_bzero(map, sizeof(t_map));
	// ft_bzero(img, sizeof(t_img));
	ft_bzero(mlx, sizeof(t_mlx));
}

// putting in pixels into the window's image
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window_esc(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_BUTTON)
	{
		cleanup(mlx);
		exit(0);
	}
	return (0);
}

int	close_window_x(t_mlx *mlx)
{
	cleanup(mlx);
	exit(0);
	return (0);
}

void cleanup(t_mlx *mlx)
{
	if (!mlx)
		return ;
	free_map(&mlx->mapping);
    if (mlx->mlx)
	{
		if (mlx->picture.img)
            mlx_destroy_image(mlx->mlx, mlx->picture.img);
        if (mlx->win)
            mlx_destroy_window(mlx->mlx, mlx->win);
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
        mlx->mlx = NULL;
    }
}
