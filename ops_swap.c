/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:25:56 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/11 15:54:00 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **c)
{
	t_list	*first;
	t_list	*second;

	if (!c || !*c || !(*c)->next)
		return ;
	first = *c;
	second = (*c)->next;
	first->next = second->next;
	second->next = first;
	*c = second;
}

void	sa(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap (a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap (b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	int	flag;

	flag = 0;
	if (a && *a && (*a)->next)
	{
		swap(a);
		flag = 1;
	}
	if (b && *b && (*b)->next)
	{
		swap(b);
		flag = 1;
	}
	if (flag)
		write(1, "ss\n", 3);
}
