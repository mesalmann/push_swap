#include "push_swap.h"

int find_index(t_list *head, int v)
{
    t_list	*tmp;
	int		i;
	
	i = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->content == v)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int count(int pos, int size)
{
    if (pos < 0 || size <= 1)
        return (0);
    if (pos <= size / 2)
        return (pos);
    else
        return (size - pos);
}

int find_cost(t_list *a, int val)
{
    int size_a;
    int pos_a;
    
    size_a = ft_list_size(a);
    pos_a = find_index(a, val);
    return (count(pos_a, size_a));
}

int min_val(int c, t_list *b)
{
    t_list	*temp;
	int		flag;
	int		match;
	int		max;
	
	if (!b)
		return (0);
	flag = 0;
	match = 0;
	max = b->content;
	temp = b;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		if (temp->content < c && (!flag || temp->content > match))
		{
			match = temp->content;
			flag = 1;
		}
		temp = temp->next;
	}
	if (flag)
		return (match);
	return (max);
}

void    make_head(t_list **a, int pos, int size)
{
    int i;
    
    i = 0;
	if (pos < 0 || pos >= size || size <= 1)
		return;
	if (pos <= size / 2)
	{
		while (i++ < pos)
			ra(a);
	}
	else
	{
		while (i++ < size - pos)
			rra(a);
	}
}
static int find_target_in_a(t_list *a, int b_val)
{
   t_list	*temp;
	int		flag;
	int		match;
	int		min;
	
	if (!a)
		return (0);
	flag = 0;
	match = 0;
	min = a->content;
	temp = a;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	temp = a;
	while (temp)
	{
		if (temp->content > b_val && (!flag || temp->content < match))
		{
			match = temp->content;
			flag = 1;
		}
		temp = temp->next;
	}
	if (flag)
		return (match);
	return (min);
}

static void push_back_to_a(t_list **a, t_list **b)
{
    int target;
    
    while (*b)
    {
        target = find_target_in_a(*a, (*b)->content);
        make_head(a, find_index(*a, target), ft_list_size(*a));
        pa(a, b);
    }
}

void    sort_large(t_list **a, t_list **b)
{
    t_list  *curr;
    int     match;
    int     best_cost;
    int     best_a_val;
    int     best_b_match;
    int     cost;
    
    if (!a || !*a || !(*a)->next)
        return ;
    pb(a, b);
    pb(a, b);
    
    while (ft_list_size(*a) > 3)
    {
        curr = *a;
        match = min_val(curr->content, *b);
        best_cost = find_cost(*a, curr->content) + find_cost(*b, match) + 1;
        best_a_val = curr->content;
        best_b_match = match;
        
        curr = *a;
        while (curr)
        {
            match = min_val(curr->content, *b);
            cost = find_cost(*a, curr->content) + find_cost(*b, match) + 1;
            if (cost < best_cost)
            {
                best_cost = cost;
                best_a_val = curr->content;
                best_b_match = match;
            }
            curr = curr->next;
        }
        make_head(a, find_index(*a, best_a_val), ft_list_size(*a));
        make_head(b, find_index(*b, best_b_match), ft_list_size(*b));
        pb(a, b);
    }
    sort_three(a);
    push_back_to_a(a, b);

     int     min;
    t_list  *t;

    t = *a;
    min = t->content;
    while (t)
    {
        if (t->content < min)
            min = t->content;
        t = t->next;
    }
    make_head(a, find_index(*a, min), ft_list_size(*a));
}