/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesalman <mesalman@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:01:38 by mesalman          #+#    #+#             */
/*   Updated: 2025/09/24 13:01:42 by mesalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    append_node(t_list **a, int val)
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
        while(cur->next)
            cur = cur->next;
        cur->next = n;
    }
}

static int  has_dup(t_list *a, int val)
{
    while(a)
    {
        if (a->content == val)
            return (1);
        a = a->next;
    }
    return (0);
}

static void sign_handle(const char *str, int *start, int *len, long *sign, t_list **a)
{
    if (*len == 0) //sayı yoksa error
        exit_with_error(a);
    if (str[*start] == '-' || str[*start] == '+') 
    {
        if (*len == 1) //sadece "+" ya da "-" gibi durumlar error
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
    int i;

    i = 0;
    res = 0;
    sign = 1;
    sign_handle(str, &start, &len, &sign, a); // - li durumları handle ediyoruz 
    while (i < len)
    {
        if (str[start + i] < '0' || str[start + i] > '9')//is valid number kontrolü yapıyoruz
            exit_with_error(a);
        res = res * 10 + sign * (str[start + i] - '0');//int min max kontrolü yapabilmek için longa çeviriyoruz 
        if (res > INT_MAX || res < INT_MIN)//int min-max kontrolü 
            exit_with_error(a);
        i++;       
    }
    return((int) res);//sonucu inte çeviriyoruz çünkü structta contentimizin tipini integer yaptık
}

static void parse_arg(t_list **a, const char *s)
{
    int i;
    int start;
    int val;

    i = 0;
    start = 0;
    if (!s || !s[0]) //string yoksa ya da boşsa error
        exit_with_error(a);
    while(s[i])
    {
        while(s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))) //boşluk olduğu sürece ilerle
           i++;
        if (!s[i]) //boşluktan sonra string bitmişse döngüden çık
            break;
        start = i; //sayının başladığı yer 
        while(s[i] && !(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
            i++;
        val = safe_atoi_long(s, start, i - start, a); // stringimizi int min-max kontrolü yapmak ve integera çevirmke için fonksiyona koyuyoruz.
        if (has_dup(*a, val)) // stackte aynı değer daha önce varsa bu bir error durumudur 
            exit_with_error(a);
        append_node(a, val); // kontrolden geçmiş değerimizi node a koyup listenin sonuna ekliyoruz
    }
}

void    build_stack(t_list **a, int argc, char **argv)
{
    int j;

    j = 1;
    if (!a)
        exit_with_error(a);
    while(j < argc)
    { //argümanları sırayla ayırıyoruz
        parse_arg(a, argv[j]);
        j++;
    }
}
