/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabilongo <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:16 by rabilongo         #+#    #+#             */
/*   Updated: 2021/09/29 17:24:26 by rabilongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft/ft_lst.h>
#include <stdlib.h>
#include <stdio.h>

// TODO: function to free elements in tab

int	free_tab_return(t_global *tab)
{
	if (!tab)
		return (0);
	if (tab->head_a)
		ft_lstclear(&tab->head_a, free);
	if (tab->head_b)
		ft_lstclear(&tab->head_b, free);
	free(tab);
	return (0);
}

int	initialise_tab(t_global *tab, int *arr)
{
	int	cnt;
	int	i;
	int	j;
	int	*tmp;

	i = -1;
	while (arr[++i])
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return (1);
		cnt = 0;
		j = -1;
		while (arr[++j])
			if (j != i && arr[j] < arr[i])
				cnt++;
		*tmp = cnt;
		ft_lstadd_back(&tab->head_a, ft_lstnew(tmp));
		tmp = NULL;
	}
	free(arr);
	return (0);
}