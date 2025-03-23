/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:07:28 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 12:51:49 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int len = 0; - Keep track of num of characters printed
// RETURN VALUE of PRINTF = numbers of characters printed excluding \0
// PRINTF is a VARIADIC FN = can take a variable num of args/ directives(0++) 
// 							of different types
// ft_printf("%d, %c", 42, n)
// 			  ------   -----
// const char *format  (...)-variable num of arguments
//
// (data type/an array= va_list)
// used with
// (macros= va_start, va_arg, va_end) to retrieve those arguments
// 										its like malloc, free
// search up them by terminalling man stdarg && man 3 printf
// 		FLOW in FT_PRINTF:
// 1- va_list args : Declaration an array of elements 
//                   of the list/arguments for the ellipsis (...)
//					: acts as a handle to access 
//					  the variable arguments (...) in a variadic function.
//
// 2- va_start(args, format) : 
// 		# args: The target to initialize for accessing the variable arguments.
// 		# s: The marker to locate where the variable arguments begin,
//			 the last known parameter in the fn.	
//
// 3- va_arg(args, type) : the standard way to retrieve arguments from (...)
// 			 	Retrieves the next argument from args as the specified type.
// a- default argument promotions.(C standard rules)
// 		# interger promotion : any int type smaller than int (short, char) is
//					promoted to int, will casted the original type on va_arg
// 		# float promotion : float promoted to double
//		###promotions in C ensure consistent arg sizes and avoids complexity 
//        when processing them
//
// 4- va_end(args) : cleans up after processing arguments, 
//      			after that args are undefined
//
// ## args (the va_list object) is used by the macros to handle (...)
// 				The macros start with args coz they are designed to process 
// 				the variable arguments, not the named ones like format.
//
// hex - 1 & 0: flags, tells fn to format number in 0 = lowerhex, 1 = upperhex
// 
// %s - man page might show const char * (which reflects modern C usage)
// %s - internally, the original design of printf was built around char *
// C language auto supports const char * as a valid argument type for %s
// 
// ft_process_format function only reads from the pointer  
// 		without needing to change its value, so 1 pointer is enough
// 
// While %c in man 3 printf converts to unsigned char,
// for simplicity and consistency in ft_printf, 
// follow the man stdarg example ((char) va_arg(ap, int))

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_process_format(format, args);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_process_format(const char *format, va_list args)
{
	int		len;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len += ft_printf_putnbr(va_arg(args, int));
	else if (*format == 'c')
		len += ft_printf_putchar((char)va_arg(args, int));
	else if (*format == 's')
		len += ft_printf_putstr(va_arg(args, char *));
	else if (*format == 'p')
		len += ft_printf_pointer(va_arg(args, void *));
	else if (*format == 'u')
		len += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		len += ft_printf_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		len += ft_printf_hex(va_arg(args, unsigned int), 1);
	else if (*format == '%')
		len += ft_printf_putchar('%');
	return (len);
}

// #include <stdio.h>

// int	main()
// {
// 	int	test = NULL;

// 	printf("Character %c\n", 'z');
// 	ft_printf("FT_P: Character %c\n\n", 'z');

// 	printf("Name: %s\n", "Aisyah");
// 	ft_printf("FT_P: Name: %s\n\n", "Aisyah");

// 	printf("Milestone: %d, the %ind one\n", 1, 2);
// 	ft_printf("FT_P: Milestone: %d, the %ind one\n\n", 1, 2);

// 	printf("Positive value 8: %u\nNegative value -1: %u\n", 8, -1);
// 	ft_printf("FT_P: Positive num 8: %u\nFT_P: Negative num -1: %u\n\n", 8, -1);
//
// 	printf("Pointer for number NULL is %p\n", NULL);
// 	ft_printf("FT_P: Pointer for number NULL is %p\n\n", NULL);

// 	printf("Hexadecimal(lower) for number 2025 is %x\n", 2025);
// 	ft_printf("FT_P: Hexadecimal(lower) for number 2025 is %x\n\n", 2025);

// 	printf("Hexadecimal(upper) for number 2025 is %X\n", 2025);
// 	ft_printf("FT_P: Hexadecimal(upper) for number 2025 is %X\n\n", 2025);
//
// 	printf("Our project handle %%cspdiuxX%% only\n");
// 	ft_printf("FT_P: Our project handle %%cspdiuxX%% only\n");
//
// 	return (0);
// }
