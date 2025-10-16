/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:01:38 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/16 19:46:54 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_whitespace(const char *s, int i)
{
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	return (i);
}

int	parse_number(const char *s, int *i, t_list **a)
{
	int	start;
	int	val;

	start = *i;
	while (s[*i] && !(s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13)))
		(*i)++;
	val = safe_atoi_long(s, start, *i - start, a);
	return (val);
}

void	parse_arg(t_list **a, const char *s)
{
	int	i;
	int	val;
	int	have_num;

	if (!s)
		exit_with_error(a);
	i = 0;
	have_num = 0;
	while (s[i])
	{
		i = skip_whitespace(s, i);
		if (!s[i])
			break ;
		val = parse_number(s, &i, a);
		if (has_dup(*a, val))
			exit_with_error(a);
		append_node(a, val);
		have_num = 1;
	}
	if (!have_num)
		exit_with_error(a);
}

void	build_stack(t_list **a, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		parse_arg(a, av[i]);
		i++;
	}
}
