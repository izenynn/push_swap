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

static int	push(t_dlist **dst, t_dlist **src)
{
	int	d_sz;
	int	s_sz;

	d_sz = ft_dlstsize(*dst);
	s_sz = ft_dlstsize(*src);
	if (s_sz < 1)
		return (1);
	if (s_sz == 1)
	{
		(*src)->next = *dst;
		*dst = *src;
		*src = NULL;
	}
	else
	{
		*src = (*src)->next;
		(*src)->prev->next = *dst;
		*dst = (*src)->prev;
		(*src)->prev = NULL;
	}
	if (d_sz)
		(*dst)->next->prev = *dst;
	return (0);
}

void	pa(t_global *tab)
{
	if (push(&tab->head_a, &tab->head_b))
		return ;
	ft_printf("pa\n");
}

void	pb(t_global *tab)
{
	if (push(&tab->head_b, &tab->head_a))
		return ;
	ft_printf("pb\n");
}
