/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:13:09 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 11:13:10 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft/ft_dlst.h>
#include <libft/ft_printf.h>

static int	swap(t_dlist **head)
{
	int	sz;

	sz = ft_dlstsize(*head);
	if (sz < 2)
		return (1);
	if (sz == 2)
	{
		(*head)->next->next = *head;
		*head = (*head)->next;
		(*head)->next->next = NULL;
		(*head)->prev = NULL;
		(*head)->next->prev = *head;
	}
	else
	{
		(*head)->next = (*head)->next->next;
		(*head)->next->prev->next = *head;
		(*head)->prev = (*head)->next->prev;
		(*head)->next->prev->prev = NULL;
		(*head)->next->prev = *head;
		*head = (*head)->prev;
	}
	return (0);
}

void	sa(t_global *tab)
{
	if (swap(&tab->head_a))
		return ;
	ft_printf("sa\n");
}

void	sb(t_global *tab)
{
	if (swap(&tab->head_b))
		return ;
	ft_printf("sb\n");
}

void	ss(t_global *tab)
{
	int	print;

	print = 1;
	if (swap(&tab->head_a))
		print = 0;
	if (swap(&tab->head_b))
		print = 0;
	if (print)
		ft_printf("ss\n");
}
