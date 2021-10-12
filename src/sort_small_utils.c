/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:58:51 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/12 12:58:58 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	smart_rotate(t_global *tab, int n)
{
	if (n > tab->a_sz / 2)
	{
		n = tab->a_sz - n;
		while (n--)
			rra(tab);
	}
	else
		while (n--)
			ra(tab);

}

void	smart_push(t_global *tab)
{
	if (is_min(tab->head_a, tab->head_b))
	{
		sort_a(tab);
		pa(tab);
	}
	else if (is_max(tab->head_a, tab->head_b))
	{
		sort_a(tab);
		pa(tab);
		ra(tab);
	}
	else
	{
		smart_rotate(tab, get_ins_pos(tab->head_a, *(int *)tab->head_b->data));
		pa(tab);
	}
}

void	sort_a(t_global *tab)
{
	int	cnt;

	cnt = 0;
	tab->a = tab->head_a;
	while (tab->a)
	{
		if (is_min(tab->head_a, tab->a))
			break ;
		cnt++;
		tab->a = tab->a->next;
	}
	smart_rotate(tab, cnt);
}