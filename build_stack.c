/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:01:38 by mesalman          #+#    #+#             */
/*   Updated: 2025/10/04 13:03:34 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    append_node(t_list **a, int val)
{
    t_list *n;
    t_list *cur;

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

static int  has_dup(t_list *a, int val)
{
    while (a)
    {
        if (a->content == val)
            return (1);
        a = a->next;
    }
    return (0);
}

static void sign_handle(const char *str, int *start, int *len, long *sign, t_list **a)
{
    if (*len == 0)
        exit_with_error(a);
    if (str[*start] == '-' || str[*start] == '+')
    {
        if (*len == 1)
            exit_with_error(a);
        if (str[*start] == '-')
            *sign = -1;
        *start = *start + 1;
        *len = *len - 1;
    }
}

static int  safe_atoi_long(const char *str, int start, int len, t_list **a)
{
    long res;
    long sign;
    int  i;

    i = 0;
    res = 0;
    sign = 1;
    sign_handle(str, &start, &len, &sign, a);
    while (i < len)
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

static void parse_arg(t_list **a, const char *s)
{
    int i;
    int start;
    int val;
    int have_num;

    i = 0;
    start = 0;
    have_num = 0;
    if (!s)
        exit_with_error(a);
    while (s[i])
    {
        while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
            i++;
        if (!s[i])
            break;
        start = i;
        while (s[i] && !(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
            i++;
        val = safe_atoi_long(s, start, i - start, a);
        if (has_dup(*a, val))
            exit_with_error(a);
        append_node(a, val);
        have_num = 1;
    }
    if (!have_num)
        exit_with_error(a);
}

void    build_stack(t_list **a, int argc, char **argv)
{
    int j;

    j = 1;
    while (j < argc)
    {
        parse_arg(a, argv[j]);
        j++;
    }
}

