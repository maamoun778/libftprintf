/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hafi <mel-hafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:19:16 by mel-hafi          #+#    #+#             */
/*   Updated: 2024/11/19 11:53:20 by mel-hafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex_ptr(unsigned long long ptr, size_t *counter)
{
	if (ptr >= 16)
	{
		ft_put_hex_ptr(ptr / 16, counter);
		ft_put_hex_ptr(ptr % 16, counter);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_pf((ptr + '0'), counter);
		else
			ft_putchar_pf((ptr - 10 + 'a'), counter);
	}
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (!addr)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	ft_putstr_pf("0x", counter);
	ft_put_hex_ptr(addr, counter);
}
/* int main()
{
	size_t count = 0;
	int nb = 42;
	void *ptr = &nb;
	ft_putptr_pf(ptr,&count);
} */