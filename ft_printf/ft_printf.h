/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:01:02 by blidriss          #+#    #+#             */
/*   Updated: 2025/11/09 11:26:56 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format(char format, va_list arg);
//print_handler.
int		ft_string(char *str);
int		ft_char(char c);
int		ft_integer(int n);
int		ft_unsigned_int(unsigned int n);
int		ft_print_hexa(unsigned int n, char x_X);
void	hexa_convertor(unsigned int n, char c);
int		ft_address(unsigned long addr);

#endif
