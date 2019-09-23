/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarlon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:34:33 by fkarlon           #+#    #+#             */
/*   Updated: 2019/08/11 18:42:51 by fkarlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test(char **array, int i, int j)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 9)
		if ((array[i][a++] == array[i][j]) && (a - 1 != j))
			return (0);
	while (b < 9)
		if ((array[b++][j] == array[i][j]) && (b - 1 != i))
			return (0);
	a = (j / 3) * 3;
	b = (i / 3) * 3;
	while (b < (i / 3) * 3 + 3)
	{
		while (a < (j / 3) * 3 + 3)
			if ((array[b][a++] == array[i][j]) && (b != i) && (a - 1 != j))
				return (0);
		b++;
		a = (j / 3) * 3;
	}
	return (1);
}