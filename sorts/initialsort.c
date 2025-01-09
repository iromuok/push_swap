/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:52:24 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 15:52:27 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **a)
{
	if ((*a)->next->next)
	{
		if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->content > (*a)->next->next->content)
				ra(*a);
		}
		else
		{
			if ((*a)->next->content < (*a)->next->next->content)
				return ;
			else
				rra(*a);
		}
	}
	if ((*a)->content > (*a)->next->content)
		sa(*a);
}

int	findsmallpos(t_list *lsttmp)
{
	int	i;
	int	j;
	int	tmp;

	j = 1;
	i = 1;
	tmp = lsttmp->content;
	while (lsttmp->next)
	{
		j++;
		if (tmp > lsttmp->next->content)
		{
			i = j;
			tmp = lsttmp->next->content;
		}
		lsttmp = lsttmp->next;
	}
	return (i);
}

void	pushsmallest(t_list **a, t_list **b)
{
	int	i;

	i = findsmallpos(*a);
	if (i > 3)
	{
		while (i++ <= ft_lstsize(*a))
			rra(*a);
	}
	else if (i > 1)
		ra(*a);
	if (findsmallpos(*a) != 1)
		sa(*a);
	pb(a, b);
	if (ft_lstsize(*a) == 3)
		return ;
	i = findsmallpos(*a);
	if (i == 2)
		sa(*a);
	else if (i != 1)
	{
		while (i++ <= 4)
			rra(*a);
	}
	pb(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 3)
		pushsmallest(a, b);
	sort_three(a);
	if (checksort(*a, *b))
		return ;
	while (*b)
		pa(a, b);
}
