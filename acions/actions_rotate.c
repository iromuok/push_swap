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

void	ra(t_list *stacka)
{
	rotate(stacka);
	write (1, "ra\n", 3);
}

void	rb(t_list *stackb)
{
	rotate(stackb);
	write (1, "rb\n", 3);
}

void	rr(t_list *stacka, t_list *stackb)
{
	rotate(stacka);
	rotate(stackb);
	write (1, "rr\n", 3);
}
