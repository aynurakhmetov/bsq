/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:35:06 by gmarva            #+#    #+#             */
/*   Updated: 2020/02/26 17:46:02 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int				sideinstr(char **str, int i, int j, struct s_info xl)
{
	int k;

	k = 0;
	while (i < xl.strok)
	{
		if (str[i][j] == xl.bas)
			k++;
		else
			break ;
		i++;
	}
	return (k);
}

int				width(char **str, int i, int j, struct s_info xl)
{
	int k;

	k = 0;
	while (j < xl.len)
	{
		if (str[i][j] == xl.bas)
			k++;
		else
			return (k);
		j++;
	}
	return (k);
}

int				side(char **str, int i, int j, struct s_info xl)
{
	struct s_sqrdo	m;
	int				k;
	int				s;
	int				w;

	w = width(str, i, j, xl);
	m.j = j;
	m.i = i;
	m.a = 0;
	s = w + 1;
	while (j < m.j + w)
	{
		i = m.i;
		k = 0;
		k = sideinstr(str, i, j, xl);
		if (k <= s)
			s = k;
		j++;
		m.a++;
		if (s == m.a)
			return (s);
	}
	return (s);
}

struct	s_sqrdo	findsqr(int w, int s, int i, int j)
{
	struct s_sqrdo	m;

	if (s <= w)
		m.a = s;
	if (w <= s)
		m.a = w;
	m.i = i;
	m.j = j;
	return (m);
}

void			msqr(char **str, struct s_info xl)
{
	int				i;
	int				j;
	int				w;
	int				s;
	struct s_sqrdo	m;

	m.a = 0;
	i = 1;
	while (i < xl.strok)
	{
		j = 0;
		while (j < xl.len)
		{
			w = width(str, i, j, xl);
			s = side(str, i, j, xl);
			if ((m.a < w && w <= s) || (m.a < s && s <= w))
				m = findsqr(w, s, i, j);
			j++;
		}
		i++;
	}
	printsqr(m, str, xl);
}
