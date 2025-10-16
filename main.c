/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:16:58 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/11 15:49:21 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	build_stack(&stack_a, argv);
	sort_stack(&stack_a, &stack_b);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}
