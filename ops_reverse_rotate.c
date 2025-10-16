/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:38:26 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/11 15:51:31 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **a)
{
	t_list	*tail;
	t_list	*head;

	if (!a || !*a || !(*a)->next)
		return ;
	tail = *a;
	while (tail->next->next)
		tail = tail->next;
	head = tail->next;
	tail->next = NULL;
	head->next = *a;
	*a = head;
}

void	rra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	int	flag;

	flag = 0;
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		flag = 1;
	}
	if (b && *b && (*b)->next)
	{
		reverse_rotate(b);
		flag = 1;
	}
	if (flag)
		write(1, "rrr\n", 4);
}
