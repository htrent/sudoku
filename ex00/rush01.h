/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeraldi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:29:38 by rjeraldi          #+#    #+#             */
/*   Updated: 2019/08/11 23:32:00 by rjeraldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		recursive_up(char **argv, char **arr, int i, int j);
int		recursive_down(char **argv, char **arr, int i, int j);
void	ft_print_error(void);
int		test(char **array, int i, int j);
int		check_array(char **arr);
int		check(int argc, char **argv, int i, int j);
int		printarr(int i, int j, char **arr);
char	**putzero(char **argv);
char	**putcolon(char **argv);
int		compare(char **arr, char **argv, int i, int j);
int		compare_arrays(char **arr1, char **arr2);
int		re_compare(char **arr, char **argv, int i, int j);
int		re_recursive_down(char **argv, char **arr, int i, int j);
int		re_recursive_up(char **argv, char **arr, int i, int j);

#endif
