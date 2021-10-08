/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:51 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/08 11:46:22 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_sorted(t_dlist *head)
{
	while (head->next)
	{
		if (*(int *)head->content > *(int *)head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	handle_sort(int n_cnt, t_global *tab)
{
	if (n_cnt < 2 || is_sorted(tab->head_a))
		return ;
	if (n_cnt == 2)
		if (*(int *)tab->head_a->content > *(int *)tab->head_a->next->content)
			sa(tab);
}
