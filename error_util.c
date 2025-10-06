/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:48:25 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:49:35 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **a)
{
	t_list *temp;

	if(!a || !*a)
		return ;
	temp = *a;
	while(*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void	exit_with_error(t_list **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}