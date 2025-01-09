/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionbackend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:04:19 by sbat              #+#    #+#             */
/*   Updated: 2024/12/29 21:04:24 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list *stack)
{
	int	tmp;

	if (!stack)
		return ;
	if (!stack->next)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (!*stack2)
		return ;
	tmp = *stack2;
	*stack2 = (*stack2)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack1, tmp);
}

void	rotate(t_list *lst)
{
	int	first;

	if (!lst)
		return ;
	if (!lst->next)
		return ;
	first = lst->content;
	while (lst->next)
	{
		lst->content = lst->next->content;
		lst = lst->next;
	}
	lst->content = first;
}

void	rrotate(t_list *lst)
{
	t_list	*lsttmp;
	int		tmp;

	if (!lst)
		return ;
	if (!lst->next)
		return ;
	lsttmp = lst;
	lst = lst->next;
	while (lst)
	{
		tmp = lst->content;
		lst->content = lsttmp->content;
		lsttmp->content = tmp;
		lst = lst->next;
	}
}
