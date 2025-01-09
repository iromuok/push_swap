/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:50:35 by sbat              #+#    #+#             */
/*   Updated: 2024/11/22 09:50:49 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	ft_strchr(char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (0);
	i = 0;
	ch = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (i + 1);
		i++;
	}
	if (ch == '\0')
		return (i + 1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int er)
{
	char	*c;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s2[er] = '\0';
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		c = ft_strdup(s1);
		free(s1);
		return (c);
	}
	s2[er] = '\0';
	c = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (freestr(s1));
	i = ft_strcpy(c, s1);
	i += ft_strcpy(c + i, s2);
	return (free(s1), c);
}
