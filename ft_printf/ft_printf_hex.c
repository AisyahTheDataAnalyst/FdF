/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:48:19 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/03 19:03:09 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// hex = hexadecimal = base-16 number system
// widely used in programming and computing to 
// represent memory address, binary data, color codes
// alternative way to represent numbers, using 16 symbols
// %x = 0123456789abcdef
// %X = 0123456789ABCDEF
// ex: 123456 -> 1e240
// c = base16[n%16] = base16[15] = base16['f'] (thebiggestone)
// use unsigned int - replicate realistic printf implementation
// 		sufficient enough as most hex values fit into 32-bit space

#include "ft_printf.h"

int	ft_printf_hex(unsigned int n, int is_uppercase)
{
	int		len;
	char	*base16;
	char	c;

	len = 0;
	if (is_uppercase == 1)
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";
	if (n >= 16)
		len += ft_printf_hex(n / 16, is_uppercase);
	c = base16[n % 16];
	len += ft_printf_putchar(c);
	return (len);
}
