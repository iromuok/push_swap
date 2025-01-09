/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:30:45 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 16:30:49 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freesplit(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

int	argcheck(char *av)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (av[i])
	{
		if ((av[i] == '+' || av[i] == '-'))
		{
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				return (0);
			if (i != 0)
			{
				if (av[i - 1] != ' ')
					return (0);
			}
		}
		if (av[i] >= '0' && av[i] <= '9')
			r = 1;
		if (!(av[i] >= '0' && av[i] <= '9') && av[i] != ' ' && !(av[i] == '+'
				|| av[i] == '-'))
			return (0);
		i++;
	}
	return (r);
}

int	checkfordup(t_list *stacka)
{
	t_list	*lsttmp;

	while (stacka)
	{
		lsttmp = stacka->next;
		while (lsttmp)
		{
			if (stacka->content == lsttmp->content)
				return (0);
			lsttmp = lsttmp->next;
		}
		stacka = stacka->next;
	}
	return (1);
}

t_list	*splitargs(t_list *stacka, char *av)
{
	char	**split;
	long	tmp;
	int		j;
	t_list	*lsttmp;

	j = 0;
	split = ft_split(av, ' ');
	if (!split)
		return (ft_lstclear(&stacka), NULL);
	while (split[j])
	{
		tmp = ft_atoi(split[j]);
		if (tmp > 2147483647 || tmp < -2147483648 || ft_sstrlen(split[j]) > 11)
			return (freesplit(split), ft_lstclear(&stacka), write(2, "Error\n",
					6), NULL);
		lsttmp = ft_lstnew(tmp);
		if (!lsttmp)
			return (ft_lstclear(&stacka), NULL);
		ft_lstadd_back(&stacka, lsttmp);
		j++;
	}
	freesplit(split);
	return (stacka);
}

t_list	*initstacka(int ac, char **av)
{
	int		i;
	t_list	*stacka;

	i = 1;
	stacka = NULL;
	while (i < ac)
	{
		if (argcheck(av[i]))
			stacka = splitargs(stacka, av[i]);
		else
			return (ft_lstclear(&stacka), write(2, "Error\n", 6), NULL);
		if (!stacka)
			return (NULL);
		i++;
	}
	if (checkfordup(stacka))
		return (stacka);
	return (ft_lstclear(&stacka), write(2, "Error\n", 6), NULL);
}
