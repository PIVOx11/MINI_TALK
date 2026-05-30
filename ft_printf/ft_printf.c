/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:21:26 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/14 15:03:43 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char format, va_list arg)
{
	int	i;

	i = 0;
	if (format == 's')
		i += ft_string(va_arg(arg, char *));
	else if (format == 'c')
		i += ft_char((char )va_arg(arg, int));
	else if (format == 'd' || format == 'i')
		i += ft_integer(va_arg(arg, int));
	else if (format == 'u')
		i += ft_unsigned_int(va_arg(arg, unsigned int));
	else if (format == 'X' || format == 'x')
		i += ft_print_hexa(va_arg(arg, unsigned int), format);
	else if (format == 'p')
		i += ft_address((unsigned long)va_arg(arg, void *));
	else if (format == '%')
		i += ft_char('%');
	else if (format == '\0')
		return (0);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	if (!str)
		return (-1);
	va_start(arg, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (len);
			len += ft_format(str[i + 1], arg);
			i++;
		}
		else
			len += ft_char(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
