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

static void	sort_5(t_global *tab)
{
	n_ops(pb, tab, 2);
	sort_3(tab);
	n_ops(pa, tab, 2);
}

void	sort_small(int n_cnt, t_global *tab)
{
	if (n_cnt == 2)
	{
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->next->data)
			sa(tab);
	}
	else if (n_cnt == 3)
		sort_3(tab);
	else
		sort_5(tab);
}
