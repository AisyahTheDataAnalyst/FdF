/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:23:48 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/02 15:20:07 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// When the recursion reaches the base case (n <= 9), 
// it starts "unwinding" and prints each digit one by one.
// int_min must (-(n/10)) to not overflow the int_max, thats why 8 at the end

#include "ft_printf.h"

int	ft_printf_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
	{
		len += ft_printf_putchar('-');
		len += ft_printf_putnbr(-(n / 10));
		len += ft_printf_putchar('8');
		return (len);
	}
	if (n < 0)
	{
		len += ft_printf_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_printf_putnbr(n / 10);
	len += ft_printf_putchar(n % 10 + '0');
	return (len);
}
