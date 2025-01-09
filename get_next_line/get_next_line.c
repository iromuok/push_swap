/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:09:30 by sbat              #+#    #+#             */
/*   Updated: 2024/11/25 11:22:37 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freestr(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*ft_tmpfill(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = '\n';
		i++;
	}
	return (tmp[i] = '\0', tmp);
}

char	*ft_reset(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	else
		return (freestr(str));
	tmp = (char *)malloc(ft_strlen(str + i) + 1);
	if (!tmp)
		return (freestr(str));
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	return (tmp[j] = '\0', free(str), tmp);
}

char	*nextline(char *c, char *str, int fd)
{
	int	i;
	int	er;

	er = 1;
	i = 0;
	while (er > 0 && !i)
	{
		er = read(fd, c, BUFFER_SIZE);
		if (er == -1)
			return (free(c), freestr(str));
		if (!er)
			c = freestr(c);
		str = ft_strjoin(str, c, er);
		i = ft_strchr(str, '\n');
	}
	if (c)
		free(c);
	return (str);
}

char	*get_next_line(int fd, int i)
{
	static char	*str;
	char		*c;
	char		*tmp;

	if (!i)
		return (free(str), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!c)
		return (freestr(str));
	str = nextline(c, str, fd);
	if (!str || (str && str[0] == '\0'))
		return (freestr(str));
	tmp = ft_tmpfill(str);
	str = ft_reset(str);
	return (tmp);
}
