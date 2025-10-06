/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:38 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:46:17 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **c)
{
	t_list	*first;
	t_list	*tail;

	if (!c || !*c || !(*c)->next)
		return ;
	first = *c;
	tail = *c;
	while (tail->next)
		tail = tail->next;
	*c = first->next;
	tail->next = first;
	first->next = NULL;
}

void	ra(t_list **a)
{
 	if (!a || !*a || !(*a)->next) 
 		return;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	if (!b || !*b || !(*b)->next) 
 		return;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	int	flag;
	
	flag = 0;
	if (a && *a && (*a)->next)
	{
		rotate(a);
		flag = 1;
	}
	if (b && *b && (*b)->next)
	{
		rotate(b);
		flag = 1;
	}
	if (flag)
		write(1, "rr\n", 3);
}
