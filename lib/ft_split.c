/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:18:05 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 15:50:33 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wordsplit(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		i;

	if (!s || !c)
	{
		words = malloc(sizeof(char*));
		words[0] = NULL;
		return (words);
	}
	if (!(words = (char **)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			words[i++] = ft_wordsplit(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	words[i] = NULL;
	return (words);
}
