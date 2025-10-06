/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:34:32 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/02 12:35:18 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_list *a)
{
	int size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return size;
}

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return 0;
		a = a->next;
	}
	return 1;
}

static int	find_position(t_list *tmp, int target)
{
	int pos = 0;

	while (tmp)
	{
		if (tmp->content == target)
			return pos;
		tmp = tmp->next;
		pos++;
	}
	return -1;
}

static void	up(t_list **a, int pos, int size)
{
	int i = 0;

	if (pos < 0 || size <= 1)
		return;
	if (pos <= size / 2)
		while (i++ < pos)
			ra(a);
	else
		while (i++ < size - pos)
			rra(a);
}


void	sort_two(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return;
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_three(t_list **a)
{
	int x, y, z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return;
	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;

	if (x > y && x < z)                      /* 2 1 3 */
		sa(a);
	else if (x > y && y > z)                 /* 3 2 1 */
	{
		sa(a);
		rra(a);
	}
	else if (x > z && y < z)                 /* 3 1 2 */
		ra(a);
	else if (x < y && x > z)                 /* 2 3 1 */
		rra(a);
	else if (x < y && y > z && x < z)        /* 1 3 2 */
	{
		sa(a);
		ra(a);
	}
}

void	sort_maxfive(t_list **a, t_list **b)
{
	int     size;
	int     pos;
	int     min;
	t_list  *tmp;

	size = ft_list_size(*a);
	while (size > 3)
	{
		/* min'i bul */
		tmp = *a;
		min = tmp->content;
		while (tmp)
		{
			if (tmp->content < min)
				min = tmp->content;
			tmp = tmp->next;
		}
		/* min'i tepeye getir ve b'ye it */
		pos = find_position(*a, min);
		up(a, pos, size);
		pb(a, b);
		size--;
	}
	/* kalan 3'ü sırala ve geri topla */
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stack(t_list **a, t_list **b)
{
	int size;

	if (!a || !*a)
		return;
	if (is_sorted(*a))
		return;

	size = ft_list_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
		sort_large(a, b);
}
