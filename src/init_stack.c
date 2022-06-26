/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:37:57 by bfiguet           #+#    #+#             */
/*   Updated: 2022/06/10 15:33:03 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_min_index(t_stacks **s, int content)
{
	t_stacks	*head;
	int			i;

	head = *s;
	i = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < i) && head->index != content)
			i = head->index;
	}
	return (i);
}

void	ft_add_index(t_stacks **s)
{
	t_stacks	*head;
	int			index;

	index = 0;
	head = ft_get_min(s);
	while (head)
	{
		head->index = index++;
		head = ft_get_min(s);
	}
}

void	ft_check_arg(int ac, char **av)
{
	int		i;
	long	tmp;

	i = 0;
	if (*av && ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 1;
	while (av[i])
	{
		tmp = ft_atol(av[i]);
		if (!ft_str_isdigit(av[i]) || ft_repeat(tmp, av, i)
			|| tmp < -2147483648 || tmp > 2147483647)
		{
			ft_printf("Error\n");
			exit (0);
		}
		i++;
	}
	if (ac == 2)
		ft_free_str(av);
}

void	ft_init_stack(t_stacks **s, int ac, char **av)
{
	t_stacks	*new;
	int			i;

	i = 0;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 1;
	while (av[i])
	{
		new = ft_new(ft_atoi(av[i]));
		ft_add_back(s, new);
		i++;
	}
	ft_add_index(s);
	if (ac == 2)
		ft_free_str(av);
}
