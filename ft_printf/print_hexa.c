/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:22:00 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/09 11:13:15 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int n, char x_X)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = n;
	if (n == 0)
	{
		ft_char('0');
		return (1);
	}
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	if (x_X == 'x')
		hexa_convertor(n, 'x');
	else
		hexa_convertor(n, 'X');
	return (len);
}
