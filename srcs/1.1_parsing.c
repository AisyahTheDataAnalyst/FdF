/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:46:58 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/27 12:13:08 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void parse_map_row(char **av, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**row_values;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return ;
	map->grid = malloc(map->row * sizeof(t_pixel *));
	if (!(map->grid))
		exit(1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < map->row)
	{
		row_values = ft_split(line, ' ');
		parse_column_colour_z(map, i, row_values);
		free_line_row_values(line, row_values);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}

// use row_values[j] instead of row_values[i][j] 
// coz row_values itself is already the [i].
// colour  += 2; ==same== colour = &colour[2]; 
// - moving 2 points forward
void	parse_column_colour_z(t_map *map, int i, char **row_values)
{
	int		j;
	t_pixel	pixel;
	char	**split;

	j = 0;
	map->grid[i] = malloc(map->column * sizeof(t_pixel));
	if (!(map->grid[i]))
		return ;
	while (j < map->column && row_values[j])
	{
		if (ft_strchr(row_values[j], ','))
		{
			split = ft_split(row_values[j], ',');
			if (split && split[0] && split[1])
				parse_colour_z_unique(split, &pixel);
			else
				parse_colour_z_normal(&pixel, row_values, j);
			freeing_split(split);
		}
		else
			parse_colour_z_normal(&pixel, row_values, j);
		parse_x_y(map, &pixel, i, j);
		j++;
	}
}

void	parse_colour_z_normal(t_pixel *pixel, char **row_values, int j)
{
	pixel->colour = 0xFFFFFF;
	pixel->z = ft_atoi(row_values[j]);
}

void	parse_x_y(t_map *map, t_pixel *pixel, int i, int j)
{
	pixel->x = i;
	pixel->y = j;
	map->grid[i][j] = *pixel;
}

void	parse_colour_z_unique(char **split, t_pixel *pixel)
{
	char	*colour;

	pixel->z = ft_atoi(split[0]);
	colour = (split[1]);
	if (colour[0] == '0' && (colour[1] == 'x' || colour[1] == 'X'))
		colour += 2;
	// printf("raw colour string %s\n", colour);
	pixel->colour = ft_atoi_base_unsigned(colour, 16);
	// printf("parsed colour: %u\n", pixel->colour);
}
