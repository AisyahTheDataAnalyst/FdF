/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:46:58 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/10 14:42:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	parse_map_height(char **av, t_map *map, t_pixel *pixel)
{
	int		fd;
	int		i;
	char	*line;
	char	**height_values;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	map->grid = malloc(map->height * sizeof(t_pixel *));
	if (!(map->grid))
		exit(1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < map->height)
	{
		height_values = ft_split(line, ' ');
		parse_width(map, i, height_values, pixel);
		free_line_height_values(line, height_values);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}

// use height_values[j] instead of height_values[i][j] 
// coz height_values itself is already the [i].
// colour  += 2; ==same== colour = &colour[2]; 
// - moving 2 points forward
void	parse_width(t_map *map, int i, char **height_values, t_pixel *pixel)
{
	int		j;
	char	**split;

	j = 0;
	map->grid[i] = malloc(map->width * sizeof(t_pixel));
	if (!(map->grid[i]))
		return ;
	while (j < map->width && height_values[j])
	{
		if (ft_strchr(height_values[j], ','))
		{
			split = ft_split(height_values[j], ',');
			if (split && split[0] && split[1])
				parse_colour_z_unique(split, pixel);
			else
				parse_colour_z_normal(pixel, height_values, j);
			freeing_split(split);
		}
		else
			parse_colour_z_normal(pixel, height_values, j);
		parse_x_y(map, pixel, i, j);
		j++;
	}
}

void	parse_colour_z_normal(t_pixel *pixel, char **height_values, int j)
{
	pixel->colour = DEFAULT_COLOUR;
	pixel->z = ft_atoi(height_values[j]);
	pixel->ori_z = pixel->z;
}

void	parse_x_y(t_map *map, t_pixel *pixel, int i, int j)
{
	pixel->x = j;
	pixel->y = i;
	pixel->ori_x = j;
	pixel->ori_y = i;
	map->grid[i][j] = *pixel;
}

void	parse_colour_z_unique(char **split, t_pixel *pixel)
{
	char	*colour;

	pixel->z = ft_atoi(split[0]);
	pixel->ori_z = pixel->z;
	colour = (split[1]);
	if (colour[0] == '0' && (colour[1] == 'x' || colour[1] == 'X'))
		colour += 2;
	pixel->colour = ft_atoi_base(colour, 16);
}
