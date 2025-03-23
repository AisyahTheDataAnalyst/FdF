/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:16:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/03 19:25:34 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// %p = memory address
// unsigned int - 32-bit, unsigned long long- 64-bit system to include windows
// for windows, unsigned long with cover 32-bit only despite not like mac/linux
// for mac/linux, unsigned long cover 64-bit
// unsigned long long for pointer safety
// pointer use 0 for hex, lowercase only
// but decided to use unsigned long long too for hex_ll because 
//		pointer function will use hex too, so better be consistent
//		no data loss for pointers

#include "ft_printf.h"

static int	ft_printf_hex_ll(unsigned long long n, int is_uppercase)
{
	int		len;
	char	*base16;
	char	c;

	if (is_uppercase == 1)
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_printf_hex_ll(n / 16, is_uppercase);
	c = base16[n % 16];
	len += ft_printf_putchar(c);
	return (len);
}

int	ft_printf_pointer(void *ptr)
{
	unsigned long long	num;
	int					len;

	if (!ptr)
		return (ft_printf_putstr("(nil)"));
	num = (unsigned long long)ptr;
	len = 0;
	len += ft_printf_putstr("0x");
	len += ft_printf_hex_ll(num, 0);
	return (len);
}
