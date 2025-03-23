/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:26:33 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/03 18:48:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// write, va_list, INT_MIN 
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);

int	ft_process_format(const char *format, va_list args);

int	ft_printf_putnbr(int n);

int	ft_printf_putchar(char c);

int	ft_printf_putstr(char *str);

int	ft_printf_pointer(void *ptr);

int	ft_printf_unsigned(unsigned int n);

int	ft_printf_hex(unsigned int n, int is_uppercase);

#endif