/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:09:58 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/13 17:10:05 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	try_push_next(t_global *tab, int swap)
{
	if (*(int *)tab->head_b->data == tab->b_sz - 2 && !swap)
	{
		pa(tab);
		return (1);
	}
	return (0);
}

int	smart_rotate_b(t_global *tab)
{
	int	cnt;
	int	swap;
	int	sz;

	cnt = 0;
	swap = 0;
	sz = tab->b_sz;
	tab->b = tab->head_b;
	while (*(int *)tab->b->data != sz - 1 && ++cnt)
		tab->b = tab->b->next;
	while (*(int *)tab->head_b->data != sz - 1)
	{
		if (!try_push_next(tab, swap))
		{
			if (cnt > sz / 2)
				rrb(tab);
			else
				rb(tab);
		}
		else
			swap = 1;
	}
	return (swap);
}