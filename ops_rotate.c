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
	rotate(a);
}

void	rb(t_list **b)
{
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}