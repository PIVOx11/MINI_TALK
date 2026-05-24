/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:29:31 by blidriss          #+#    #+#             */
/*   Updated: 2025/10/24 09:26:45 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_malloc;
	int		i;

	if (!s || !f)
		return (NULL);
	s_malloc = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_malloc)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_malloc[i] = f(i, s[i]);
		i++;
	}
	s_malloc[i] = '\0';
	return (s_malloc);
}
