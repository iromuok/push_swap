/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:48:41 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 15:48:45 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	if (!src)
		return (0);
	slen = 0;
	while (src[slen])
		slen++;
	i = 0;
	if (dstsize == 0 || !dst)
		return (slen);
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

static size_t	countwords(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			l++;
		while (*s && *s != c)
			s++;
	}
	return (l);
}

static char	**freeing(char **c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(c[i]);
		i++;
	}
	free(c);
	return (NULL);
}

static void	wordlen(const char *s, char c, size_t *d, size_t *b)
{
	while (s[*b] == c && s[*b])
		*b = *b + 1;
	*d = *b;
	while (s[*b] != c && s[*b])
		*b = *b + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;
	size_t	j;
	size_t	d;
	size_t	b;

	if (!s)
		return (NULL);
	count = countwords(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (freeing(str, 0));
	j = 0;
	b = 0;
	while (j < count)
	{
		wordlen(s, c, &d, &b);
		str[j] = (char *)malloc(sizeof(char) * (b - d + 1));
		if (!str[j])
			return (freeing(str, j));
		ft_strlcpy(str[j++], s + d, b - d + 1);
	}
	str[count] = NULL;
	return (str);
}
