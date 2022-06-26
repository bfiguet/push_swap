/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:00:22 by bfiguet           #+#    #+#             */
/*   Updated: 2022/05/30 18:44:32 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stack_size(t_stacks *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

int	ft_repeat(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atol(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_order(t_stacks **s)
{
	t_stacks	*head;

	head = *s;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_stacks **s)
{
	t_stacks	*head;
	t_stacks	*tmp;

	head = *s;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(s);
}
