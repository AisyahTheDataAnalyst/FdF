/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:51:17 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/10 13:44:29 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main ()
{
		const char *str = "Mamammia";
		char ch = 'm';
		char *result = ft_strrchr(str, ch);

		printf("%s\n", result);

		if (result != NULL)
			printf("%c is found last at the %zdth\n", ch, result - str + 1);
		else
			printf("%c is not found\n", ch);


		int index = result - str + 1;
		printf ("Character %c is found last at the %dth position\n", ch, index);

		return (0);
}*/