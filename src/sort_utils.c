/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:27:56 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/11 15:28:05 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void n_ops(void (*op)(t_global *), t_global *tab, int n)
{
	while (n--)
		op(tab);
}

int	is_sorted(t_dlist *head)
{
	while (head->next)
	{
		if (*(int *)head->data > *(int *)head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_min(t_dlist *head, t_dlist *element)
{
	;
}

int	is_max(t_dlist *head, t_dlist *element)
{
	;
}