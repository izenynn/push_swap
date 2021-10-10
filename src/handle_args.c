/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:10:34 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/06 18:10:43 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft/ft_str.h>
#include <libft/ft_fd.h>
#include <libft/ft_nbr.h>
#include <stdlib.h>

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

static int	check_repeat(int *arr, int n_cnt)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n_cnt)
	{
		j = i;
		while (++j < n_cnt)
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

static int	handle_check(int n_cnt, char **nbrs, int **arr)
{
	if (n_cnt < 1 || check_args(nbrs))
		return (1);
	*arr = create_int_arr(n_cnt, nbrs);
	if (!*arr)
		return (1);
	if (check_repeat(*arr, n_cnt))
	{
		free(*arr);
		return (1);
	}
	return (0);
}

static char	**parse_args(int ac, char **av)
{
	char	**nbrs;
	char	*av_str;
	char	*tmp;
	int		i;

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
	free(av_str);
	return (nbrs);
}

int	handle_args(int ac, char **av, int **arr)
{
	char	**nbrs;
	int		i;
	int		n_cnt;

	nbrs = parse_args(ac, av);
	n_cnt = 0;
	i = -1;
	while (nbrs[++i])
		n_cnt++;
	if (handle_check(n_cnt, nbrs, arr))
		n_cnt = -1;
	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
	if (n_cnt < 0)
	{
		ft_putstr_fd("Error\n", 2);
	}
	return (n_cnt);
}
