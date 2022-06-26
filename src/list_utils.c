/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:03:00 by bfiguet           #+#    #+#             */
/*   Updated: 2022/06/10 15:32:25 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stacks	*ft_get_last(t_stacks *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_front(t_stacks **s, t_stacks *new)
{
	if (!new)
		return ;
	new->next = *s;
	*s = new;
}

void	ft_add_back(t_stacks **s, t_stacks *new)
{
	t_stacks	*tmp;

	if (!new)
		return ;
	if (*s)
	{
		tmp = ft_get_last(*s);
		tmp->next = new;
	}
	else
		*s = new;
}

t_stacks	*ft_get_min(t_stacks **s)
{
	t_stacks	*head;
	t_stacks	*min;
	int			i;

	min = NULL;
	head = *s;
	i = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!i || head->content
					< min->content))
			{
				min = head;
				i = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

t_stacks	*ft_new(int content)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}
