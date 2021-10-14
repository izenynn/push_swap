/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:09:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/13 17:09:26 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_push_chunk_dir(t_global *tab, int chunk_sz, int chunk_n)
{
	int	cnt;
	int	pos_first;
	int	pos_last;

	cnt = 0;
	pos_first = -1;
	pos_last = 0;
	tab->a = tab->head_a;
	while (tab->a)
	{
		if (*(int *)tab->a->data < chunk_sz * chunk_n)
		{
			if (pos_first < 0)
				pos_first = cnt;
			pos_last = cnt;
		}
		cnt++;
		tab->a = tab->a->next;
	}
	if (pos_last < tab->a_sz - pos_first)
		return (1);
	return (0);
	// 8, 3, sz: 20
	// 8, 20 - 3 = 17
}

static void	push_in_chunks(t_global *tab, int chunk_sz)
{
	int	chunk_n;
	int	cnt;
	int	dir;

	chunk_n = 1;
	cnt = 0;
	dir = get_push_chunk_dir(tab, chunk_sz, chunk_n);
	while (tab->a_sz)
	{
		if (*(int *)tab->head_a->data < (chunk_sz * chunk_n))
		{
			pb(tab);
			if (*(int *)tab->head_b->data
				>= chunk_sz * chunk_n - (chunk_sz / 2))
				rb(tab);
			cnt++;
		}
		else if (dir)
			rra(tab);
		else
			ra(tab);
		if (cnt == chunk_sz * chunk_n)
		{
			chunk_n++;
			dir = get_push_chunk_dir(tab, chunk_sz, chunk_n);
		}
	}
}

static void	push_back_in_order(t_global *tab)
{
	while (tab->b_sz)
	{
		if (smart_rotate_b(tab))
		{
			pa(tab);
			if (tab->b_sz > 1
				&& *(int *)tab->head_b->data < *(int *)tab->head_b->next->data)
				ss(tab);
			else
				sa(tab);
		}
		else
			pa(tab);
	}
}

void	sort_big(t_global *tab)
{
	int	chunk_sz;

	chunk_sz = tab->a_sz / 13 + 22;
	while (chunk_sz % 5)
		chunk_sz++;
	push_in_chunks(tab, chunk_sz);
	push_back_in_order(tab);
}
