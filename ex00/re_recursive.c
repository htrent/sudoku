/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:25:53 by htrent            #+#    #+#             */
/*   Updated: 2019/08/11 23:30:16 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		re_check_rec_up(char **arr, int i, int j)
{
	if (j == 0 && i > 0)
	{
		arr[i][j] = ':';
		return (1);
	}
	else if (j != 0 && i >= 0)
	{
		arr[i][j] = ':';
		return (-1);
	}
	else if (j == 8 && i == 8)
		return (0);
	else
		return (0);
}

int		re_recursive_up(char **argv, char **arr, int i, int j)
{
	if (re_compare(argv, arr, i, j))
		if (--arr[i][j] < '1')
			if (re_check_rec_up(arr, i, j) == 1)
				return (re_recursive_down(argv, arr, i - 1, 8));
			else if (re_check_rec_up(arr, i, j) == -1)
				return (re_recursive_down(argv, arr, i, j - 1));
			else
				return (0);
		else if (test(arr, i, j))
			if (j == 8 && i == 8)
				return (1);
			else if (j == 8)
				return (re_recursive_up(argv, arr, i + 1, 0));
			else
				return (re_recursive_up(argv, arr, i, j + 1));
		else
			return (re_recursive_up(argv, arr, i, j));
	else if (i == 8 && j == 8)
		return (1);
	else if (j == 8)
		return (re_recursive_up(argv, arr, i + 1, 0));
	else
		return (re_recursive_up(argv, arr, i, j + 1));
	return (0);
}

int		re_recursive_down(char **argv, char **arr, int i, int j)
{
	if (re_compare(argv, arr, i, j))
		return (re_recursive_up(argv, arr, i, j));
	else
	{
		if (j == 0 && i > 0)
			return (re_recursive_down(argv, arr, i - 1, 9));
		else if (j > 0 && i >= 0)
			return (re_recursive_down(argv, arr, i, j - 1));
		else
			return (0);
	}
}

int		re_compare(char **argv, char **arr, int i, int j)
{
	if (arr[i][j] == argv[i + 1][j])
		return (0);
	else
		return (1);
}
