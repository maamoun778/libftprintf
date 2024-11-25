/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hafi <mel-hafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:19:30 by mel-hafi          #+#    #+#             */
/*   Updated: 2024/11/19 11:48:37 by mel-hafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_pf(unsigned int nb, char format, size_t *counter)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_puthex_pf(nb / 16, format, counter);
	ft_putchar_pf(base[nb % 16], counter);
}
/* int main()
{

	size_t foom = 0;
	ft_puthex_pf(8655,'X',&foom);

} */
