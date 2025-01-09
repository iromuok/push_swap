/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:03:22 by sbat              #+#    #+#             */
/*   Updated: 2024/12/29 21:03:25 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list *stacka)
{
	rrotate(stacka);
	write (1, "rra\n", 4);
}

void	rrb(t_list *stackb)
{
	rrotate(stackb);
	write (1, "rrb\n", 4);
}

void	rrr(t_list *stacka, t_list *stackb)
{
	rrotate(stacka);
	rrotate(stackb);
	write (1, "rrr\n", 4);
}
