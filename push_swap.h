/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:02:44 by sbat              #+#    #+#             */
/*   Updated: 2024/12/29 21:05:37 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <limits.h>

//lst utils

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

t_list	*initstacka(int ac, char **av);

//utils:

int		checksort(t_list *stacka, t_list *stackb);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *nptr);
int		ft_sstrlen(char *str);

//sort_utils
void	getsmallest(t_list *lsttmp, int *arr, int i);
int		getindex(int a, int *arr, int stacksize);
void	converttoarr(t_list *b, int *arr, int stacksize);
int		getbiggest(t_list *b);

//sorts:

void	sort_five(t_list **a, t_list **b);
void	sortall(t_list **a, t_list **b);

//actions:
void	swap(t_list *stack);
void	push(t_list **stack1, t_list **stack2);
void	del(void *content);
void	rotate(t_list *lst);
void	rrotate(t_list *lst);

void	sa(t_list *stacka);
void	sb(t_list *stackb);
void	ss(t_list *stacka, t_list *stackb);

void	pa(t_list **stacka, t_list **stackb);
void	pb(t_list **stacka, t_list **stackb);

void	ra(t_list *stacka);
void	rb(t_list *stackb);
void	rr(t_list *stacka, t_list *stackb);

void	rra(t_list *stacka);
void	rrb(t_list *stackb);
void	rrr(t_list *stacka, t_list *stackb);

void	sa_bonus(t_list *stacka);
void	sb_bonus(t_list *stackb);
void	ss_bonus(t_list *stacka, t_list *stackb);

void	pa_bonus(t_list **stacka, t_list **stackb);
void	pb_bonus(t_list **stacka, t_list **stackb);

void	ra_bonus(t_list *stacka);
void	rb_bonus(t_list *stackb);
void	rr_bonus(t_list *stacka, t_list *stackb);

void	rra_bonus(t_list *stacka);
void	rrb_bonus(t_list *stackb);
void	rrr_bonus(t_list *stacka, t_list *stackb);

char	*get_next_line(int fd, int i);

#endif
