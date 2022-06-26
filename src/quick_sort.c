/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:47:10 by bfiguet           #+#    #+#             */
/*   Updated: 2022/06/10 15:35:19 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include<stdio.h>

void	ft_three(t_stacks **s_a)
{
	if (((*s_a)->index > (*s_a)->next->index)
		&& ((*s_a)->index > (*s_a)->next->next->index))
	{
		ra(s_a);
		if ((*s_a)->index > (*s_a)->next->index)
			sa(s_a);
	}
	else if ((*s_a)->next->index > (*s_a)->next->next->index)
	{
		rra(s_a);
		if ((*s_a)->index > (*s_a)->next->index)
			sa(s_a);
	}
	else if ((*s_a)->index > (*s_a)->next->index)
		sa(s_a);
}

void	ft_four(t_stacks **s_a, t_stacks **s_b)
{
	int			min;
	t_stacks	*last;

	min = ft_min_index(s_a, -1);
	last = ft_get_last(*s_a);
	if (last->index == min)
		rra(s_a);
	else if ((*s_a)->next->index == min)
		sa(s_a);
	else if ((*s_a)->next->next->index == min)
	{
		rra(s_a);
		rra(s_a);
	}
	if (!ft_order(s_a))
	{	
		pb(s_a, s_b);
		ft_three(s_a);
		pa(s_b, s_a);
	}
}

void	ft_five(t_stacks **s_a, t_stacks **s_b)
{
	int			min;
	t_stacks	*last;

	min = ft_min_index(s_a, -1);
	last = ft_get_last(*s_a);
	if (last->index == min)
		rra(s_a);
	else if ((*s_a)->next->index == min)
		sa(s_a);
	else if ((*s_a)->next->next->index == min)
	{
		ra(s_a);
		ra(s_a);
	}
	else if ((*s_a)->next->next->next->index == min)
	{
		rra(s_a);
		rra(s_a);
	}
	if (ft_order(s_a))
		return ;
	pb(s_a, s_b);
	ft_four(s_a, s_b);
	pa(s_b, s_a);
}

void	ft_sort(t_stacks **s_a, t_stacks **s_b)
{
	int	size;

	if (!ft_order(s_a) || !ft_stack_size(*s_a) == 0
		|| ft_stack_size(*s_a) != 1)
	{
		size = ft_stack_size(*s_a);
		if (size == 2)
			sa(s_a);
		else if (size == 3)
			ft_three(s_a);
		else if (size == 4)
			ft_four(s_a, s_b);
		else if (size == 5)
			ft_five(s_a, s_b);
		else
			ft_radix_sort(s_a, s_b);
	}
}
