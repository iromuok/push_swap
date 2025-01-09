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

void	sa_bonus(t_list *stacka)
{
	swap(stacka);
}

void	sb_bonus(t_list *stackb)
{
	swap(stackb);
}

void	ss_bonus(t_list *stacka, t_list *stackb)
{
	swap(stacka);
	swap(stackb);
}

void	pa_bonus(t_list **stacka, t_list **stackb)
{
	push(stacka, stackb);
}

void	pb_bonus(t_list **stacka, t_list **stackb)
{
	push(stackb, stacka);
}
