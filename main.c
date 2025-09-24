/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:16:58 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 17:24:42 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);

	build_stack(stack_a, argc, argv);
	
	//sort

	free_list (&stack_a);
	free_list (&stack_b);
}