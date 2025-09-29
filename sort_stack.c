/* **************** ********************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:45:47 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/26 15:57:48 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_list_size(t_list **a)
{
	int size = 0;
	while(*a)
	{
		size++;
		*a = (*a)->next;
	}
	return(size);
}

int	is_sorted(t_list **a)
{
	while(*a)
	{
		if((*a)->content >= (*a)->next->content)
			return (0);
		*a = (*a)->next;
	}
	return(1);
}

void	sort_two(t_list **a)
{
	sa(*a);
}

void	sort_three(t_list **a)
{
	int	top;
	int 	mid;
	int	bot;

	top = (*a)->content;
	mid = (*a)->next->content;
	bot = (*a)->next->next->content;

	if (mid >= top && bot >= top)
		sa(a);
	else if (mid >=top && mid >= bot)
		rra(a);
	else if (top >= mid && top >= bot)
	{
		sa(a);
		rra(a);
	}
	else if (top >= mid && bot >= mid)
		ra(a);
	else
	{
		sa(a);
		ra(a);
	}
}

void	sort_maxfive(t_list **a, t_list **b)
{
	t_list	*iter;
	t_list	*temp;
	t_list	*min_node;
	int	min;
	
	temp = *a;
	iter = *a;
	min_node = *a;
	min = (*a)->content;
	
	while (iter->next)
	{
		if (iter->content < min)	
		{
			min = iter->content;
			min_node = iter;
		}
		iter = iter->next;
	}
	
	if (min_node != *a)
	{	
		while(temp->next != min_node)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		min_node->next = *a;
		*a = min_node;
	}
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lst_size(*a);
	
	if (is_sorted(*a))
		return ;		
} 
