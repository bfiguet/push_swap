/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:42:13 by bfiguet           #+#    #+#             */
/*   Updated: 2022/05/30 18:49:08 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stacks **s)
{
	t_stacks	*tmp;

	if (ft_stack_size(*s) > 2)
	{
		tmp = (*s)->next;
		(*s)->next = tmp->next;
		tmp->next = *s;
		*s = tmp;
	}
}

void	sa(t_stacks **s_a)
{
	swap(s_a);
	ft_printf("sa\n");
}

void	sb(t_stacks **s_b)
{
	swap(s_b);
	ft_printf("sb\n");
}

void	ss(t_stacks **s_a, t_stacks **s_b)
{
	swap(s_a);
	swap(s_b);
	ft_printf("ss\n");
}
