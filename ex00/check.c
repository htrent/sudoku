/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarlon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:16:24 by fkarlon           #+#    #+#             */
/*   Updated: 2019/08/11 23:29:50 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *st)
{
	while (*st)
	{
		ft_putchar(*st);
		st++;
	}
}

int		check(int argc, char **argv, int j, int i)
{
	if (argc != 10)
	{
		ft_putstr("Error\n");
		return (0);
	}
	argc = 0;
	while (i < 10)
	{
		while (argv[i][j] != '\0')
			if (argv[i][j++] != '.')
				argc++;
		if (j != 9)
		{
			ft_putstr("Error\n");
			return (0);
		}
		j = 0;
		i++;
	}
	if (argc < 17)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

char	**putcolon(char **argv)
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
				arr[i][j] = ':';
			else
				arr[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
	return (arr);
}

int		compare_arrays(char **arr1, char **arr2)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (arr1[i][j] != arr2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
