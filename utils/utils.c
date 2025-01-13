/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:49:00 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 15:49:03 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sstrlen(char *str)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i + l])
		l++;
	return (l + (*str == '-'));
}

int	checksort(t_list *stacka, t_list *stackb)
{
	if (stackb || !stacka)
		return (0);
	while (stacka->next)
	{
		if ((stacka->content) > (stacka->next->content))
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

long	ft_atoi(const char *nptr)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = sign + (-2 * (nptr[i] == '-'));
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}
