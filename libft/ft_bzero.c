/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:42:20 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/20 18:42:25 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// unsigned char - better practice esp on raw memory manipulation fn
// 		- align with how real bzero works also
// another way to do is to use memset
// since this is a ray memory maipulation fn, - no usages of null terminating
// no error handling of if (n ++ 0) is needed,unnecessary cluter&complexity
// 		- it will just skip the loop and its a no-op(does nothing)
// output: will null terminate the 1st n characters, but will not have output
// 			- no output coz already null terminated
// 			- %.5s is to show at most 5 characters only 
// 				(but nothing printed since the front has been null terminated)

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "Aloha";
	size_t	n = 3;
	
	printf("Before ft_bzero : %s\n", s);
	ft_bzero(s, n);
	printf("After ft_bzero : %.5s\n", s); //Output: \0\0\0ha 
	return (0);
}*/
