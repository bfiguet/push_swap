/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:41:04 by bfiguet           #+#    #+#             */
/*   Updated: 2022/05/30 18:39:01 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rot(t_stacks **s)
{
	t_stacks	*head;
	t_stacks	*end;

	if (ft_stack_size(*s) >= 2)
	{
		end = ft_get_last(*s);
		head = *s;
		*s = (*s)->next;
		end->next = head;
		head->next = NULL;
	}	
}

void	ra(t_stacks **s_a)
{
	rot(s_a);
	ft_printf("ra\n");
}

void	rb(t_stacks **s_b)
{
	rot(s_b);
	ft_printf("rb\n");
}

void	rr(t_stacks **s_a, t_stacks **s_b)
{
	rot(s_a);
	rot(s_b);
	ft_printf("rr");
}
