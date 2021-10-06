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

static int	*create_int_arr(int n_cnt, char **nbrs)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * n_cnt);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < n_cnt)
		arr[i] = ft_atoi(nbrs[i]);
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

int	handle_check(int n_cnt, char **nbrs, int **arr)
{
	if (n_cnt < 1 || check_args(n_cnt, nbrs))
		return (1);
	*arr = create_int_arr(n_cnt, nbrs);
	if (!*arr)
		return (1);
	if (check_repeat(*arr))
	{
		free(*arr);
		return (1);
	}
	return (0);
}

int	handle_args(int ac, char **av, int **arr)
{
	char	**nbrs;
	char	*av_str;
	char	*tmp;
	int		i;
	int		n_cnt;

	av_str = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		tmp = ft_strjoin(av_str, av[i]);
		free(av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free(av_str);
		av_str = tmp;
	}
	nbrs = ft_split(av_str, ' ');
	n_cnt = 0;
	i = -1;
	while (nbrs[++i])
		n_cnt++;
	if (handle_check(n_cnt, nbrs, arr))
		return (-1);
	return (n_cnt);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int	*arr;
	int	n_cnt;

	n_cnt = handle_args(ac, av, &arr);
	if (n_cnt < 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (!arr)
			free(arr);
		//system("leaks -q push_swap");
		return (1);
	}
	tab = create_stack();
	if (initialise_tab(tab, arr, n_cnt))
		return (1);
	// TESTS
	show_arr_tab(n_cnt, arr, tab);
	show_tab(n_cnt, tab);
	//
	free(arr);
	//system("leaks -q push_swap");
	return (free_tab_return(tab));
}