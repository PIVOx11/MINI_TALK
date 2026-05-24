/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blidriss <blidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:56:15 by blidriss          #+#    #+#             */
/*   Updated: 2025/10/29 10:45:34 by blidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	char	*ft_get_words(char *s, char c, int *index)
{
	int		end;
	int		start;
	char	*word;

	end = 0;
	start = *index;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, end - start + 1);
	*index = end;
	return (word);
}

static char	**ft_freed(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split_words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split_words = malloc((sizeof(char *)) * ((ft_count((char *)s, c)) + 1));
	if (!split_words)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			split_words[j] = ft_get_words((char *)s, c, &i);
			if (!split_words[j])
				return (ft_freed(split_words, j - 1));
			j++;
		}
	}
	split_words[j] = NULL;
	return (split_words);
}
