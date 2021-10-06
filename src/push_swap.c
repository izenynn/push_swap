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
#include <push_swap.h>

#include <libft/ft_printf.h>

// REMOVE THIS FUNC IN FINAL VERSION
static void	show_arr_tab(int n, int *arr, t_global *tab)
{
	ft_printf("\n|---------------------------|\n");
	ft_printf("|     ARR     |     TAB     |\n");
	ft_printf("|---------------------------|\n");
	tab->a = tab->head_a;
	for (int i = 0; i < n - 1; i++)
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
	ft_printf("\n|-------------|\n");
	ft_printf("|     TAB     |\n");
	ft_printf("|-------------|\n");
	tab->a = tab->head_a;
	for (int i = 0; i < n - 1; i++)
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

static int	*create_int_arr(int ac, char **av)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (ac));
	if (!arr)
		return (NULL);
	i = 0;
	while (++i < ac)
		arr[i - 1] = ft_atoi(av[i]);
	arr[i - 1] = 0;
	return (arr);
}

static int	check_repeat(int *arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

int	handle_args(int ac, char **av, int **arr)
{
	if (ac < 2 || check_args(ac, av))
		return (1);
	*arr = create_int_arr(ac, av);
	if (!*arr)
		return (1);
	if (check_repeat(*arr))
	{
		free(*arr);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int	*arr;

	if (handle_args(ac, av, &arr))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		//system("leaks -q push_swap");
		return (1);
	}
	tab = create_stack();
	if (initialise_tab(tab, arr, ac))
		return (1);
	// REMOVE THIS LINE
	show_arr_tab(ac, arr, tab);
	show_tab(ac, tab);
	//
	free(arr);
	//system("leaks -q push_swap");
	return (free_tab_return(tab));
}