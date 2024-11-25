/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hafi <mel-hafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:12:19 by mel-hafi          #+#    #+#             */
/*   Updated: 2024/11/19 11:52:31 by mel-hafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int nb, size_t *counter)
{
	if (nb == -2147483648)
	{
		ft_putstr_pf("-2147483648", counter);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_pf('-', counter);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_pf((nb / 10), counter);
	ft_putchar_pf(('0' + nb % 10), counter);
}
