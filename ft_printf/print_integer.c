/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:57 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/09 17:02:38 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_char('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_char((nb % 10) + 48);
}

int	ft_integer(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	ft_putnbr(n);
	if (nb == 0)
	{
		i++;
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
