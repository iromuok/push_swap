/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:38:06 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 16:38:10 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list *stacka)
{
	swap(stacka);
	write (1, "sa\n", 3);
}

void	sb(t_list *stackb)
{
	swap(stackb);
	write (1, "sb\n", 3);
}

void	ss(t_list *stacka, t_list *stackb)
{
	swap(stacka);
	swap(stackb);
	write (1, "ss\n", 3);
}

void	pa(t_list **stacka, t_list **stackb)
{
	push(stacka, stackb);
	write (1, "pa\n", 3);
}

void	pb(t_list **stacka, t_list **stackb)
{
	push(stackb, stacka);
	write (1, "pb\n", 3);
}
