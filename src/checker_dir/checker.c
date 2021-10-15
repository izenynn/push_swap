/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:30:35 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/15 01:30:42 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft/ft_str.h>
#include <libft/ft_fd.h>
#include <stdlib.h>
#include <unistd.h>

static void	err_exit(t_global *tab)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	free_tab(tab);
	exit(EXIT_SUCCESS);
}

static int	is_sorted(t_global *tab, int n_cnt)
{
	if (tab->b_sz || tab->a_sz != n_cnt)
		return (0);
	tab->a = tab->head_a;
	while (tab->a->next)
	{
		if (*(int *)tab->a->data > *(int *)tab->a->next->data)
			return (0);
		tab->a = tab->a->next;
	}
	return (1);
}

static void	eval_line(t_global *tab, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(tab, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(tab, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(tab, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(tab, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(tab, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(tab, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(tab, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(tab, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(tab, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(tab, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(tab, 0);
	else
		err_exit(tab);
}

static void	handle_check(t_global *tab, int n_cnt)
{
	char	*line;

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		eval_line(tab, line);
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
	}
	free(line);
	if (!is_sorted(tab, n_cnt))
	{
		ft_putstr_fd("KO\n", STDOUT_FILENO);
		exit (EXIT_SUCCESS);
	}
	ft_putstr_fd("OK\n", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int			*arr;
	int			n_cnt;

	if (ac == 1)
		return (EXIT_SUCCESS);
	n_cnt = handle_args(ac, av, &arr);
	if (n_cnt < 0)
		return (EXIT_FAILURE);
	tab = create_stack();
	if (initialise_tab(tab, arr, n_cnt))
	{
		free(arr);
		return (EXIT_FAILURE);
	}
	free(arr);
	handle_check(tab, n_cnt);
	free_tab(tab);
	return (EXIT_SUCCESS);
}