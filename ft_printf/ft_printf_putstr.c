/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:23:45 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/02 15:19:22 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return type: ssize_t write is compatible with int ft_printf_str
// ssize_t and int are both signed int
// ssize_t = result of fn, a size (+ve, 0,) or error (-1)

#include "ft_printf.h"

int	ft_printf_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_printf_putchar(*str++);
		len++;
	}
	return (len);
}
