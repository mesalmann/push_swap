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

int main(int argc, char **argv)
{
	//a ve b stacki oluştur
	t_list	*stack_a;
	t_list	*stack_b;

	//argüman yoksa programı bitir
	if (argc =< 1)
		return (0);

	
	build_stack();
	
	//sort-----loading-----

	//stackleri freele
	free_stack (&stack_a);
	free_stack (&stack_b);
}
