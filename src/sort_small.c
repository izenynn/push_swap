/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:23:23 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/08 12:27:03 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_3(t_global *tab)
{
	int	arr[3];

	arr[0] = *(int *)tab->head_a->data;
	arr[1] = *(int *)tab->head_a->next->data;
	arr[2] = *(int *)tab->head_a->next->next->data;

	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		sa(tab);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		sa(tab);
		rra(tab);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ra(tab);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		sa(tab);
		ra(tab);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rra(tab);
}

static void	sort_5(t_global *tab, int n_cnt)
{
	n_ops(pb, tab, n_cnt - 3);
	sort_3(tab);
	n_ops(smart_push, tab, n_cnt - 3);
	sort_a(tab);
}

void	sort_small(t_global *tab, int n_cnt)
{
	if (tab->a_sz == 2)
	{
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->next->data)
			sa(tab);
	}
	else if (tab->a_sz == 3)
		sort_3(tab);
	else
		sort_5(tab, n_cnt);
}
