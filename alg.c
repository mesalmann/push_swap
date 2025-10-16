/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:18:27 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/16 19:18:41 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_to_a(t_list **a, t_list **b)
{
	int	target;
	int	pos;

	while (*b)
	{
		target = find_target_in_a(*a, (*b)->content);
		pos = find_index(*a, target);
		if (pos >= 0 && ft_list_size(*a) > 1)
			make_head_a(a, pos, ft_list_size(*a));
		pa(a, b);
	}
}

static void	cost_calc(t_list **a, t_list **b, int *best_a, int *best_b)
{
	t_list	*cur;
	int		match;
	int		best_c;
	int		cost;

	cur = *a;
	match = find_target_in_b(cur->content, *b);
	best_c = find_cost(*a, cur->content) + find_cost(*b, match) + 1;
	*best_a = cur->content;
	*best_b = match;
	cur = cur->next;
	while (cur)
	{
		match = find_target_in_b(cur->content, *b);
		cost = find_cost(*a, cur->content) + find_cost(*b, match) + 1;
		if (cost < best_c)
		{
			best_c = cost;
			*best_a = cur->content;
			*best_b = match;
		}
		cur = cur->next;
	}
}

static void	push_to_b_with_min_cost(t_list **a, t_list **b)
{
	int	best_a;
	int	best_b;
	int	x;
	int	y;

	while (ft_list_size(*a) > 3)
	{
		cost_calc(a, b, &best_a, &best_b);
		x = find_index(*a, best_a);
		y = find_index(*b, best_b);
		make_head_a(a, x, ft_list_size(*a));
		make_head_b(b, y, ft_list_size(*b));
		pb(a, b);
	}
}

void	sort_large(t_list **a, t_list **b)
{
	t_list	*t;
	int		min;
	int		pos_a;

	if (!a || !(*a) || !(*a)->next)
		return ;
	pb(a, b);
	if (ft_list_size(*a) != 3)
		pb(a, b);
	push_to_b_with_min_cost(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	t = *a;
	min = t->content;
	t = t->next;
	while (t)
	{
		if (t->content < min)
			min = t->content;
		t = t->next;
	}
	pos_a = find_index(*a, min);
	if (pos_a >= 0 && ft_list_size(*a) > 1)
		make_head_a(a, pos_a, ft_list_size(*a));
}
