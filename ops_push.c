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
	push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
}
