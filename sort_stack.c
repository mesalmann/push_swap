/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:34:32 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/11 15:59:01 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_list *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_two(t_list **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x > y && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > z && y < z)
		ra(a);
	else if (x < y && x > z)
		rra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	if (!a || !(*a))
		return ;
	if (is_sorted(*a))
		return ;
	size = ft_list_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
		sort_large(a, b);
}
