/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:40:37 by blidriss          #+#    #+#             */
/*   Updated: 2025/10/24 09:26:23 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char )*s == (unsigned char )c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char )*s == (unsigned char )c)
		return ((char *)s);
	return (NULL);
}
