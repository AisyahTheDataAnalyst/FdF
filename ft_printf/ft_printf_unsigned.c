/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:48:26 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/03 18:15:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// it able to recieve -ve num, converting it into unsigned int
// 		it'll do modulo arithmetic

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_printf_unsigned(n / 10);
	len += ft_printf_putchar(n % 10 + '0');
	return (len);
}
