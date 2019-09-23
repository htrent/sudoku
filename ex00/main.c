/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:53:51 by htrent            #+#    #+#             */
/*   Updated: 2019/08/11 23:26:02 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		main(int argc, char **argv)
{
	char	**arr;
	int		i;
	int		result;
	char	**re_arr;
	int		result1;

	if (check(argc, argv, 0, 1) == 0)
		return (0);
	i = 0;
	arr = putzero(argv);
	re_arr = putcolon(argv);
	if (check_array(arr) == 0)
	{
		ft_print_error();
		return (0);
	}
	result = recursive_up(argv, arr, 0, 0);
	result1 = re_recursive_up(argv, re_arr, 0, 0);
	if (result1 == 0 || result == 0 || compare_arrays(arr, re_arr) == 0)
	{
		ft_print_error();
		return (0);
	}
	printarr(0, 0, arr);
	return (0);
}

char	**putzero(char **argv)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char*) * 9);
	while (i < 10)
		arr[i++] = (char *)malloc(sizeof(char) * 9);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i + 1][j] == '.')
				arr[i][j] = '0';
			else
				arr[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
	return (arr);
}

int		printarr(int i, int j, char **arr)
{
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(arr[i][j]);
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	i = 0;
	while (i++ < 9)
		free(arr[i - 1]);
	free(arr);
	return (0);
}

void	ft_print_error(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}

int		check_array(char **arr)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 9)
	{
		while (b < 9)
		{
			if ((arr[a][b] != '0' && arr[a][b] != ':') && test(arr, a, b) == 0)
			{
				return (0);
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}
