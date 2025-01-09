/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:05:16 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 16:05:22 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_range(int *start, int *end, int stacksize)
{
	if (*end < stacksize - 1)
		*end = *end + 1;
	if (*start < *end - 1)
		*start = *start + 1;
}

void	initrange(int *start, int *end, int stacksize)
{
	if (stacksize <= 100)
		*end = stacksize / 6;
	else
		*end = stacksize / 12;
	*start = 0;
}

void	putinb(t_list **a, t_list **b, int *arr, int stacksize)
{
	int (start), (end), (s);
	s = 0;
	initrange(&start, &end, stacksize);
	while (*a)
	{
		if (getindex((*a)->content, arr, stacksize) <= start)
		{
			if (s == 1)
				rb(*b);
			(pb(a, b), s = 1, update_range(&start, &end, stacksize));
		}
		else if (getindex((*a)->content, arr, stacksize) <= end)
		{
			if (s == 1)
				(rb(*b), s = 0);
			(pb(a, b), update_range(&start, &end, stacksize));
			if ((*b)->next && (*b)->content < (*b)->next->content)
				sb(*b);
		}
		else if (s == 1)
			(rr(*a, *b), (s = 0));
		else
			ra(*a);
	}
}

void	sortina(t_list **a, t_list **b)
{
	int	big;
	int	stacksize;
	int	*arr;
	int	i;

	while (*b)
	{
		stacksize = ft_lstsize(*b);
		arr = malloc(stacksize * sizeof(int));
		converttoarr(*b, arr, stacksize);
		big = getbiggest(*b);
		i = getindex(big, arr, stacksize);
		while ((*b)->content != big)
		{
			if (i < (stacksize / 2))
				rb(*b);
			else
				rrb(*b);
		}
		(pa(a, b), free(arr));
	}
}

void	sortall(t_list **a, t_list **b)
{
	int	*arr;
	int	i;
	int	stacksize;

	stacksize = ft_lstsize(*a);
	arr = malloc(stacksize * sizeof(int));
	i = 0;
	while (i < stacksize)
	{
		getsmallest(*a, arr, i);
		i++;
	}
	putinb(a, b, arr, stacksize);
	sortina(a, b);
	free(arr);
}
