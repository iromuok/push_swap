/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:26:28 by sbat              #+#    #+#             */
/*   Updated: 2025/01/05 18:27:47 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	applyaction(t_list **a, t_list **b, char *action)
{
	if (!ft_strcmp(action, "pa\n"))
		pa_bonus(a, b);
	else if (!ft_strcmp(action, "pb\n"))
		pb_bonus(a, b);
	else if (!ft_strcmp(action, "ra\n"))
		ra_bonus(*a);
	else if (!ft_strcmp(action, "rb\n"))
		rb_bonus(*b);
	else if (!ft_strcmp(action, "rr\n"))
		rr_bonus(*a, *b);
	else if (!ft_strcmp(action, "rra\n"))
		rra_bonus(*a);
	else if (!ft_strcmp(action, "rrb\n"))
		rrb_bonus(*b);
	else if (!ft_strcmp(action, "rrr\n"))
		rrr_bonus(*a, *b);
	else if (!ft_strcmp(action, "sa\n"))
		sa_bonus(*a);
	else if (!ft_strcmp(action, "sb\n"))
		sb_bonus(*b);
	else if (!ft_strcmp(action, "ss\n"))
		ss_bonus(*a, *b);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	finish(t_list **a, t_list **b, int i)
{
	if (!i)
		return (ft_lstclear(a), ft_lstclear(b), EXIT_FAILURE);
	if (checksort(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*action;
	int		i;

	if (ac == 1)
		return (EXIT_SUCCESS);
	b = NULL;
	a = initstacka(ac, av);
	if (!a)
		return (EXIT_FAILURE);
	action = get_next_line(0, 1);
	i = 1;
	while (action)
	{
		i = applyaction(&a, &b, action);
		free(action);
		action = get_next_line(0, i);
	}
	return (finish(&a, &b, i));
}
