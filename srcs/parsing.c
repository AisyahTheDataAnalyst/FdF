/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:46:58 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/23 14:04:49 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <errno.h>
#define ROWS 1000
#define COLUMN 1000

typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	char	*color;
}	t_pixel;

typedef struct s_map
{
	t_pixel **pixel;
	int		row;
	int		column;
}	t_map;

void	counting_row_col(char **av, t_map *map);
void	init_map(t_map *map);
void	two_d_array(char **av, t_map *map);

//aisyah you can do it! 
int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 1)
		exit(1);
	init_map(&map);
	counting_row_col(av, &map);
	two_d_array(av, &map);
	printf("Numbers of row: %d\n", map.row);
	printf("Numbers of column: %d\n", map.column);

}

void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\n' && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}


void	counting_row_col(char **av, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	line = get_next_line(fd);
	map->column = ft_wordcount(line, ' ');

	while (line)
	{
		map->row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	two_d_array(char **av, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	char **split;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		split[i] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	i = 0;
	while (map->pixel[i])
	{
		printf("%s\n", map->pixel[i]);
		i++;
	}
}
