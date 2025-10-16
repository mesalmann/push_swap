/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:39:02 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/16 19:45:54 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_list **a, int val)
{
	t_list	*n;
	t_list	*cur;

	n = malloc(sizeof(t_list));
	if (!n)
		exit_with_error(a);
	n->content = val;
	n->next = NULL;
	if (!*a)
		*a = n;
	else
	{
		cur = *a;
		while (cur->next)
			cur = cur->next;
		cur->next = n;
	}
}

int	has_dup(t_list *a, int val)
{
	while (a)
	{
		if (a->content == val)
			return (1);
		a = a->next;
	}
	return (0);
}

long	handle_sign(const char *str, int *start, int *len, t_list **a)
{
	long	sign;

	if (len == 0)
		exit_with_error(a);
	sign = 1;
	if (str[*start] == '-' || str[*start] == '+')
	{
		if (*len == 1)
			exit_with_error(a);
		if (str[*start] == '-')
			sign = -1;
		(*start)++;
		(*len)--;
	}
	return (sign);
}

int	safe_atoi_long(const char *str, int start, int len, t_list **a)
{
	long	res;
	long	sign;
	int		i;

	res = 0;
	sign = handle_sign(str, &start, &len, a);
	i = 0;
	while (i < len && str[start + i])
	{
		if (str[start + i] < '0' || str[start + i] > '9')
			exit_with_error(a);
		res = res * 10 + sign * (str[start + i] - '0');
		if (res > INT_MAX || res < INT_MIN)
			exit_with_error(a);
		i++;
	}
	return ((int)res);
}
