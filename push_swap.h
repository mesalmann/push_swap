/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:17:41 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/23 18:23:16 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_list {
	int			content;
	struct s_list	*next;
}	t_list;

void	exit_with_error(t_list **a);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	build_stack(t_list **a, int argc, char **argv);

void	sort_stack(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_two(t_list **a);
void    sort_large(t_list **a, t_list **b);
int	is_sorted(t_list *a);
int	ft_list_size(t_list *a);

void	free_stack(t_list **lst);

#endif
