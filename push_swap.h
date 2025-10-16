/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:17:41 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/16 20:46:51 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_list {
	int				content;
	struct s_list	*next;
}	t_list;
int		is_sorted(t_list *a);
int		ft_list_size(t_list *a);
int		find_index(t_list *head, int v);
int		count(int pos, int size);
int		find_cost(t_list *a, int val);
int		find_target_in_a(t_list *a, int v);
int		find_target_in_b(int c, t_list *b);
int		has_dup(t_list *a, int val);
int		list_max(t_list *lst);
int		list_min(t_list *lst);
int		safe_atoi_long(const char *str, int start, int len, t_list **a);
int		find_best_match(int c, t_list *d, int *flag, int val);
int		skip_whitespace(const char *s, int i);
int		parse_number(const char *s, int *i, t_list **a);
long	handle_sign(const char *str, int *start, int *len, t_list **a);
void	parse_arg(t_list **a, const char *s);
void	append_node(t_list **a, int val);
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
void	build_stack(t_list **a, char **argv);
void	sort_stack(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_two(t_list **a);
void	sort_large(t_list **a, t_list **b);
void	make_head_a(t_list **a, int pos, int size);
void	make_head_b(t_list **b, int pos, int size);
void	free_stack(t_list **lst);
#endif
