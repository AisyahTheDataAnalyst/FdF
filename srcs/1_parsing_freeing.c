/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing_freeing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:30:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/27 18:52:34 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	freeing_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free (map->grid);
}

void	free_line_height_values(char *line, char **height_values)
{
	int	i;

	free(line);
	i = 0;
	while (height_values[i])
	{
		free(height_values[i]);
		i++;
	}
	free(height_values);
}