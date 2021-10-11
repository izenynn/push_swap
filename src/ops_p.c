/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:13:20 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 11:13:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push(t_dlist **head_dst, t_dlist **head_src, int *d_sz, int *s_sz)
{
	if (!*head_src)
		return (1);
	if (*s_sz < 1)
		return (1);
	if (*s_sz == 1)
	{
		(*head_src)->next = *head_dst;
		*head_dst = *head_src;
		*head_src = NULL;
	}
	else
	{
		*head_src = (*head_src)->next;
		(*head_src)->prev->next = *head_dst;
		*head_dst = (*head_src)->prev;
		(*head_src)->prev = NULL;
	}
	if (*d_sz)
		(*head_dst)->next->prev = *head_dst;
	(*s_sz)--;
	(*d_sz)++;
	return (0);
}

void	pa(t_global *tab)
{
	if (push(&tab->head_a, &tab->head_b, &tab->a_sz, &tab->b_sz))
		return ;
	ft_printf("pa\n");
}

void	pb(t_global *tab)
{
	if (push(&tab->head_b, &tab->head_a, &tab->b_sz, &tab->a_sz))
		return ;
	ft_printf("pb\n");
}
