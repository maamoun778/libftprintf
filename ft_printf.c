/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hafi <mel-hafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:49:42 by mel-hafi          #+#    #+#             */
/*   Updated: 2024/11/25 12:25:00 by mel-hafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv(const char *format, va_list args, size_t *counter)
{
	if (*format == 'c')
		ft_putchar_pf(va_arg(args, int), counter);
	else if (*format == 's')
		ft_putstr_pf(va_arg(args, char *), counter);
	else if (*format == 'p')
		ft_putptr_pf(va_arg(args, void *), counter);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_pf(va_arg(args, int), counter);
	else if (*format == 'u')
		ft_putuint_pf(va_arg(args, unsigned int), counter);
	else if (*format == 'x' || *format == 'X')
		ft_puthex_pf(va_arg(args, unsigned int), *format, counter);
	else if (*format == '%')
		ft_putchar_pf('%', counter);
	else
		*counter = (size_t) - 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conv(format, args, &counter);
			if (counter == (size_t) - 1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			ft_putchar_pf(*format, &counter);
		format++;
	}
	va_end(args);
	return ((int)(counter));
}
// #include<stdio.h>
// int main()
//  {
//      int res2;
// 	void *ptr = NULL;
	// strings
	
    // res1 = ft_printf("Hello World\n");
    // res2 = printf("Hello World\n");
	
	// %c %s
	
	// res1 = ft_printf("Char: %c, String: %s\n", 'A', "test");
    // res2 = printf("Char: %c, String: %s\n", 'A', "test");
	
	// %d %i %u
	
	// res1 = ft_printf("Integer: %d, Unsigned: %u\n", -42, 42);
    // res2 = printf("Integer: %d, Unsigned: %u\n", -42, 42);
	
	// %x %X

	// res1 = ft_printf("Hex (lower): %x, Hex (upper): %X\n", 255, 255);
    // res2 = printf("Hex (lower): %x, Hex (upper): %X\n", 255, 255);

	// %p

	// res1 = ft_printf("Pointer: %p\n", ptr);
    // res2 = printf("Pointer: %p\n", ptr);

	// %%

	// res1 = ft_printf("Percentage: %%\n");
    // res2 = printf("Percentage: %%\n");     

	// invalid format

	
// printf("Testing ft_printf with %%k:\n");
// res1 = ft_printf("%k\n");
// printf("ft_printf return value: %d\n", res1);

// res2 = ft_printf("%k\n");
// ft_printf("%d",res2);
// }

