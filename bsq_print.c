/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:01:24 by gmarva            #+#    #+#             */
/*   Updated: 2020/02/26 23:18:47 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str > 0)
	{
		ft_putchar(*str);
		str++;
	}
}

void			printsqr(struct s_sqrdo m, char **str, struct s_info xl)
{
	int j;
	int i;

	j = m.j;
	i = m.i;
	while (m.i < i + m.a)
	{
		m.j = j;
		while (m.j < j + m.a)
		{
			str[m.i][m.j] = xl.re;
			m.j++;
		}
		m.i++;
	}
	i = 1;
	while (i < xl.strok)
	{
		ft_putstr(str[i]);
		i++;
	}
}

void			testbsq(char **str, struct s_info	a)
{
	int mist[5];
	int i;
	int k;

	i = 0;
	a.strok = a.strok + 1;
	k = 0;
	mist[0] = testsimb(str);
	mist[1] = test0(a);
	mist[2] = teststst(a);
	mist[3] = test0str(str, a);
	mist[4] = testcol(str, a);
	while (i < 5)
	{
		if (mist[i] == 0)
		{
			ft_putstr("map error, give me normal map");
			k++;
			break ;
		}
		i++;
	}
	if (k == 0)
		msqr(str, a);
}
