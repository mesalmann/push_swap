/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:38:34 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/16 19:41:25 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_max(t_list *lst)
{
	int	max;

	max = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	list_min(t_list *lst)
{
	int	min;

	min = lst->content;
	lst = lst->next;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	find_best_match(int c, t_list *d, int *flag, int val)
{
	int	match;

	match = 0;
	while (d)
	{
		if (val > 0 && d->content < c && (!(*flag) || d->content > match))
		{
			match = d->content;
			*flag = 1;
		}
		else if (val < 0 && d->content > c && (!(*flag) || d->content < match))
		{
			match = d->content;
			*flag = 1;
		}
		d = d->next;
	}
	return (match);
}

int	find_target_in_b(int c, t_list *b)
{
	int	flag;
	int	res;

	if (!b)
		return (0);
	flag = 0;
	res = find_best_match(c, b, &flag, 1);
	if (flag)
		return (res);
	return (list_max(b));
}

int	find_target_in_a(t_list *a, int v)
{
	int	flag;
	int	res;

	if (!a)
		return (0);
	flag = 0;
	res = find_best_match(v, a, &flag, -1);
	if (flag)
		return (res);
	return (list_min(a));
}
