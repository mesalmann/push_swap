/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:33:43 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:38:12 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **c, t_list **d)
{
	t_list	*tmp;

	if (!c || !*c || !d)
		return ;
	tmp = *c;
	*c = (*c)->next;
	tmp->next = *d;
	*d = tmp;
}

void	pb(t_list **a, t_list **b)
{
	if (!a || !*a) 
		return;
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	if (!b || !*b) 
		return;
	push(b, a);
	write(1, "pa\n", 3);
}
