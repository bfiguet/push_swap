/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:44:01 by bfiguet           #+#    #+#             */
/*   Updated: 2022/05/30 18:45:33 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rerot(t_stacks **s)
{
	t_stacks	*tmp;
	t_stacks	*end;

	if (ft_stack_size(*s) > 2)
	{
		tmp = *s;
		while (tmp->next->next)
			tmp = tmp->next;
		end = ft_get_last(*s);
		tmp->next = NULL;
		end->next = *s;
		*s = end;
	}
}

void	rra(t_stacks **s_a)
{
	rerot(s_a);
	ft_printf("rra\n");
}

void	rrb(t_stacks **s_b)
{
	rerot(s_b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks **s_a, t_stacks **s_b)
{
	rerot(s_a);
	rerot(s_b);
	ft_printf("rrr\n");
}
