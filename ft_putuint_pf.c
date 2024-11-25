/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hafi <mel-hafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:09:08 by mel-hafi          #+#    #+#             */
/*   Updated: 2024/11/19 11:52:57 by mel-hafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_pf(unsigned int nb, size_t *counter)
{
	if (nb > 9)
		ft_putuint_pf(nb / 10, counter);
	ft_putchar_pf((nb % 10) + '0', counter);
}
