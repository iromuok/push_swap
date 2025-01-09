/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:38:17 by sbat              #+#    #+#             */
/*   Updated: 2025/01/03 16:38:20 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_bonus(t_list *stacka)
{
	rotate(stacka);
}

void	rb_bonus(t_list *stackb)
{
	rotate(stackb);
}

void	rr_bonus(t_list *stacka, t_list *stackb)
{
	rotate(stacka);
	rotate(stackb);
}
