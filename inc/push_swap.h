/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:01:39 by bfiguet           #+#    #+#             */
/*   Updated: 2022/06/09 16:34:16 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

/*
* content: actual num
* index: position
* next: pointer to next node
*/

typedef struct s_stacks
{
	int				content;
	int				index;
	struct s_stacks	*next;
}				t_stacks;

//push_swap.c
void		push(t_stacks **s_src, t_stacks **s_dst);
void		pa(t_stacks **s_b, t_stacks **s_a);
void		pb(t_stacks **s_a, t_stacks **s_b);
void		ft_radix_sort(t_stacks **s_a, t_stacks **s_b);
int			main(int ac, char**av);
//utils.c
int			ft_stack_size(t_stacks *head);
int			ft_repeat(int num, char **av, int i);
int			ft_order(t_stacks **s);
void		ft_free_str(char **str);
void		ft_free_stack(t_stacks **s);
//move.c
void		swap(t_stacks **s);
void		sa(t_stacks **s_a);
void		sb(t_stacks **s_b);
void		ss(t_stacks **s_a, t_stacks **s_b);
//rot.c
void		rot(t_stacks **s);
void		ra(t_stacks **s_a);
void		rb(t_stacks **s_b);
void		rr(t_stacks **s_a, t_stacks **s_b);
//rerot.c
void		rerot(t_stacks **s);
void		rra(t_stacks **s_a);
void		rrb(t_stacks **s_b);
void		rrr(t_stacks **s_a, t_stacks **s_b);
//quick_sort.c
void		ft_three(t_stacks **s_a);
void		ft_four(t_stacks **s_a, t_stacks **s_b);
void		ft_five(t_stacks **s_a, t_stacks **s_b);
void		ft_sort(t_stacks **s_a, t_stacks **s_b);
//init_stack.c
int			ft_min_index(t_stacks **s, int content);
void		ft_add_index(t_stacks **s);
void		ft_check_arg(int ac, char **av);
void		ft_init_stack(t_stacks **s, int ac, char **av);
//list_utils.c
t_stacks	*ft_get_min(t_stacks **s);
t_stacks	*ft_new(int content);
t_stacks	*ft_get_last(t_stacks *head);
void		ft_add_front(t_stacks **s, t_stacks *new);
void		ft_add_back(t_stacks **s, t_stacks *new);

#endif
