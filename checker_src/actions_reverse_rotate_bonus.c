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

void	rra_bonus(t_list *stacka)
{
	rrotate(stacka);
}

void	rrb_bonus(t_list *stackb)
{
	rrotate(stackb);
}

void	rrr_bonus(t_list *stacka, t_list *stackb)
{
	rrotate(stacka);
	rrotate(stackb);
}
