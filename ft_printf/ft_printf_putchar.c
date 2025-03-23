/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:45:05 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/03 13:50:44 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// default fd to 1 (stdout), consistent with how standard printf works

#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
