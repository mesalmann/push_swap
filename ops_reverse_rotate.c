/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:38:26 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:42:22 by mesalman         ###   ########.fr       */
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
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}