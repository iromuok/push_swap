/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:02:07 by sbat              #+#    #+#             */
/*   Updated: 2024/12/29 21:06:10 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;

	if (ac == 1)
		return (0);
	stackb = NULL;
	stacka = initstacka(ac, av);
	if (!stacka)
		return (EXIT_FAILURE);
	if (checksort(stacka, stackb))
	{
		ft_lstclear(&stacka);
		return (EXIT_SUCCESS);
	}
	if (ft_lstsize(stacka) < 6)
		sort_five(&stacka, &stackb);
	else
		sortall(&stacka, &stackb);
	ft_lstclear(&stacka);
	return (EXIT_SUCCESS);
}
