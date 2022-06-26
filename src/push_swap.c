/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:57:28 by bfiguet           #+#    #+#             */
/*   Updated: 2022/05/30 18:47:45 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include<stdio.h>

void	push(t_stacks **s_src, t_stacks **s_dst)
{
	t_stacks	*tmp;

	if (ft_stack_size(*s_src) != 0)
	{
		tmp = *s_src;
		*s_src = (*s_src)->next;
		ft_add_front(s_dst, tmp);
	}
}

void	pa(t_stacks **s_b, t_stacks **s_a)
{
	push(s_b, s_a);
	ft_printf("pa\n");
}

void	pb(t_stacks **s_a, t_stacks **s_b)
{
	push(s_a, s_b);
	ft_printf("pb\n");
}

void	ft_radix_sort(t_stacks **s_a, t_stacks **s_b)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_stack_size(*s_a);
	while (!ft_order(s_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*s_a)->index >> i) & 1) == 1)
				ra(s_a);
			else
				pb(s_a, s_b);
		}
		while (ft_stack_size(*s_b) != 0)
			pa(s_b, s_a);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stacks	**s_a;
	t_stacks	**s_b;

	if (ac < 2)
		return (0);
	ft_check_arg(ac, av);
	s_a = malloc(sizeof(t_stacks *));
	s_b = malloc(sizeof(t_stacks *));
	*s_a = NULL;
	*s_b = NULL;
	ft_init_stack(s_a, ac, av);
	if (ft_order(s_a))
	{
		ft_free_stack(s_a);
		ft_free_stack(s_b);
		return (0);
	}
	ft_sort(s_a, s_b);
	ft_free_stack(s_a);
	ft_free_stack(s_b);
	return (0);
}
