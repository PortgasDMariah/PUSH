/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:11 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/25 20:26:17 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include <stdio.h>

int	sorted_or_not(t_data *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check(char c, char m, char b, t_data *list)
{
	if (!((ft_num(c) == 1) || (c == '-')))
		quit_well(list, 1);
	else if (c == ' ')
		quit_well(list, 1);
	else if (c == '-' && (!(ft_num(m) == 1) || (ft_num(b) == 1)))
		quit_well(list, 1);
}

int	ft_parsing(char *str, t_data *list)
{
	int			i;
	long int	a;
	long int	b;

	i = -1;
	a = 1;
	b = 0;
	if (!str || !str[0])
		quit_well(list, 1);
	while (str[++i])
	{
		check(str[i], str[i + 1], str[i - 1], list);
		if (str[i] == '-')
			a = -a;
		if (ft_num(str[i]) == 1)
			b = b * 10 + str[i] - 48;
		if (((a * b) > (2147483647)) || ((a * b) < (-2147483648)))
			quit_well(list, 1);
	}
	return (a * b);
}

void	one_arg(t_data *list, char *str)
{
	if (list->tot == 2)
	{
		ft_parsing(str, list);
		if (ft_parsing(str, list))
			quit_well(list, 0);
	}
	else if (list->tot == 1)
		quit_well(list, 0);
}
