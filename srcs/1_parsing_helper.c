/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:28:56 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/05 11:33:15 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// aisyah you can do it! 
// iniitialize to 0 or accurate counting from fresh start 
// ft_bzero for accurate counting
// need to do both
void	counting_height_width(char **av, t_map *map)
{
	int		fd;
	char	*line;

	//printf("[%s]\n", av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return ;
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	if (line)
		map->width = ft_wordcount(line, ' ');
	printf("[%d]\n", map->width);
	while (line)
	{
		//printf("line [%s]\n", line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	printf("[%d]\n", map->height);
	free(line);
	close(fd);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\n' &&
			(s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

int	char_to_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

// i >= 8
// for 6 digits RGB colours (0xRRGGBB)
// or 8 digits for alpha transparency (0xAARRGGBB)
int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	i;
	int	new;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	res = 0;
	while (str[i])
	{
		new = char_to_hex(str[i]);
		if (new == -1 || new >= str_base)
			break ;
		res = res * str_base + new;
		i++;
		if (i >= 8)
			break ;
	}
	return (res);
}
