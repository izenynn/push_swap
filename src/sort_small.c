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
	tab->a = tab->head_a->next;
	if (*(int *)tab->a->data + 1 == *(int *)tab->a->next->data)
		ra(tab);
	else if (*(int *)tab->head_a->data + 1 == *(int *)tab->a->data)
		rra(tab);
	else
	{
		sa(tab);
		if (is_sorted(tab->head_a))
			return ;
		tab->a = tab->head_a->next;
		if (*(int *)tab->a->data + 1 == *(int *)tab->a->next->data)
			ra(tab);
		else if (*(int *)tab->head_a->data + 1 == *(int *)tab->a->data)
			rra(tab);
	}
}

static void	sort_5(t_global *tab)
{
	pb(tab);
	pb(tab);
	sort_3(tab);
	//pa(tab);
	//pa(tab);
}

void	sort_small(int n_cnt, t_global *tab)
{
	if (n_cnt == 2)
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->next->data)
			sa(tab);
	if (n_cnt == 3)
		sort_3(tab);
	else
		sort_5(tab);
}
