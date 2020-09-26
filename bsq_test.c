/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:19:55 by gmarva            #+#    #+#             */
/*   Updated: 2020/02/26 23:34:12 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		testsimb(char **str)
{
	int j;
	int len;

	len = 0;
	j = 0;
	while (str[0][j] != '\n')
	{
		len++;
		j++;
	}
	j = 0;
	while (j < len - 3)
	{
		if (str[0][j] < 48 || str[0][j] > 57)
			return (0);
		j++;
	}
	return (1);
}

int		test0(struct s_info a)
{
	if (a.bas == a.let || a.bas == a.re || a.re == a.let)
		return (0);
	if (a.strok < 0)
		return (0);
	else
		return (1);
}

int		teststst(struct s_info a)
{
	if (a.strok == a.strinquad)
		return (1);
	else
		return (0);
}

int		test0str(char **str, struct s_info a)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[0][j] != '\n')
		j++;
	a.strok = a.strok - 1;
	while (a.strok > 0)
	{
		a.strok = (a.strok - a.strok % 10) / 10;
		i++;
	}
	if (j == i + 3)
		return (1);
	else
		return (0);
}

int		testcol(char **str, struct s_info a)
{
	int i;
	int j;

	i = 1;
	while (i < a.strok)
	{
		j = 0;
		while (j < a.len)
		{
            if (str[i][j] != a.bas && str[i][j] != a.let && str[i][j] != '\n')
				return (0);
			j++;
		}
        i++;
	}
	return (1);
}
