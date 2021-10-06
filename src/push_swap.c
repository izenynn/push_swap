/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:27:52 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 10:48:19 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>
#include <libft/ft_mem.h>
#include <libft/ft_fd.h>
#include <push_swap.h>

#include <libft/ft_printf.h>

// REMOVE THIS FUNC IN FINAL VERSION
static void	show_arr_tab(int n, int *arr, t_global *tab)
{
	ft_printf("\n|---------------------------|\n");
	ft_printf("|     ARR     |     TAB     |\n");
	ft_printf("|---------------------------|\n");
	tab->a = tab->head_a;
	for (int i = 0; i < n; i++)
	{
		ft_printf("| %-12d|", arr[i]);
		if (tab->a)
		{
			ft_printf(" %-12d|\n", *(int *)tab->a->content);
			tab->a = tab->a->next;
		}
		else
			ft_printf(" (null)      |\n");
	}
	ft_printf("|---------------------------|\n");
}

static void	show_tab(int n, t_global *tab)
{
	return ;
	ft_printf("\n|-------------|\n");
	ft_printf("|     TAB     |\n");
	ft_printf("|-------------|\n");
	tab->a = tab->head_a;
	for (int i = 0; i < n; i++)
	{
		if (tab->a)
		{
			ft_printf("| %-12d|\n", *(int *)tab->a->content);
			tab->a = tab->a->next;
		}
		else
			ft_printf("| (null)      |\n");
	}
	ft_printf("|-------------|\n");
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int			*arr;
	int			n_cnt;

	n_cnt = handle_args(ac, av, &arr);
	if (n_cnt < 0)
	{
		//system("leaks -q push_swap");
		return (EXIT_FAILURE);
	}
	tab = create_stack();
	if (initialise_tab(tab, arr, n_cnt))
	{
		free(arr);
		//system("leaks -q push_swap");
		return (EXIT_FAILURE);
	}
	// TESTS
	show_arr_tab(n_cnt, arr, tab);
	show_tab(n_cnt, tab);
	//
	free(arr);
	free_tab(tab);
	//system("leaks -q push_swap");
	return (EXIT_SUCCESS);
}
