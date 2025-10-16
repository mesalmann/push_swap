/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:56:54 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/09 21:06:14 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_list *head, int v)
{
	t_list	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->content == v)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	count(int pos, int size)
{
	if (pos < 0 || size <= 1)
		return (0);
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	find_cost(t_list *a, int val)
{
	int	size_a;
	int	pos_a;

	size_a = ft_list_size(a);
	pos_a = find_index(a, val);
	return (count(pos_a, size_a));
}

void	make_head_a(t_list **a, int pos, int size)
{
	int	i;

	i = 0;
	if (pos < 0 || pos >= size || size <= 1)
		return ;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

void	make_head_b(t_list **b, int pos, int size)
{
	int	i;

	i = 0;
	if (pos < 0 || pos >= size || size <= 1)
		return ;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rrb(b);
			i++;
		}
	}
}
