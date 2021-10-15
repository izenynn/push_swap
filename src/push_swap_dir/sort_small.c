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
		sa(tab, 1);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		sa(tab, 1);
		rra(tab, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ra(tab, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		sa(tab, 1);
		ra(tab, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rra(tab, 1);
}

static void	sort_5(t_global *tab, int n_cnt)
{
	if (n_cnt == 5)
		pb(tab, 1);
	pb(tab, 1);
	sort_3(tab);
	if (n_cnt == 5)
		smart_push(tab);
	smart_push(tab);
	sort_a(tab);
}

void	sort_small(t_global *tab, int n_cnt)
{
	if (tab->a_sz == 2)
	{
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->next->data)
			sa(tab, 1);
	}
	else if (tab->a_sz == 3)
		sort_3(tab);
	else
		sort_5(tab, n_cnt);
}
