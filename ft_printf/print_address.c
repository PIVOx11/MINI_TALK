/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:51 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/09 17:01:32 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recu(unsigned long hex)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (hex > 0)
	{
		ft_recu(hex / 16);
		ft_char(hexa[hex % 16]);
	}
}

int	ft_address(unsigned long addr)
{
	int	i;

	i = 2;
	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_recu(addr);
	while (addr > 0)
	{
		addr /= 16;
		i++;
	}
	return (i);
}
