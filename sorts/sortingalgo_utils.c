/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingalgo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:11:41 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 16:11:44 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	doesntexist(int *arr, int tmp, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tmp == arr[j])
			return (0);
		j++;
	}
	return (1);
}

void	getsmallest(t_list *lsttmp, int *arr, int i)
{
	arr[i] = INT_MAX;
	while (lsttmp)
	{
		if (arr[i] > lsttmp->content)
		{
			if (doesntexist(arr, lsttmp->content, i))
				arr[i] = lsttmp->content;
		}
		lsttmp = lsttmp->next;
	}
}

int	getindex(int a, int *arr, int stacksize)
{
	int	i;

	i = 0;
	while (i < stacksize)
	{
		if (a == arr[i])
			break ;
		i++;
	}
	return (i);
}

void	converttoarr(t_list *b, int *arr, int stacksize)
{
	int	i;

	i = 0;
	while (i < stacksize)
	{
		arr[i] = b->content;
		i++;
		b = b->next;
	}
}

int	getbiggest(t_list *b)
{
	int	i;

	i = INT_MIN;
	while (b)
	{
		if (i < b->content)
			i = b->content;
		b = b->next;
	}
	return (i);
}
