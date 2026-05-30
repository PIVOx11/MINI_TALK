/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:22:06 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/09 11:23:19 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr_unsigned(unsigned int n)
{
	if (n > 9)
		putnbr_unsigned(n / 10);
	ft_char((n % 10) + 48);
}

int	ft_unsigned_int(unsigned int n)
{
	int	i;

	i = 0;
	putnbr_unsigned(n);
	if (n == 0)
	{
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
