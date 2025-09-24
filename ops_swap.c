/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:25:56 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:33:09 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **c)
{
	t_list	*first;
	t_list	*second;

	if(!c || !*c || !(*c)->next)
		return ;
	first = *c;
	second = (*c)->next;
	first->next = second->next;
	second->next = first;
	*c = second;
}

void	sa(t_list **a)
{
	swap (a);
}

void	sb(t_list **b)
{
	swap (b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}