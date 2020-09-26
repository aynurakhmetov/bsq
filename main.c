/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:29:33 by hyooden           #+#    #+#             */
/*   Updated: 2020/02/26 23:30:48 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		main(int argc, char **argv)
{
	char			**str;
	int				lengthfl;
	int				i;
	struct s_info	newstruct;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str = ft_get_file(argv[i]);
			lengthfl = get_firstline_length(argv[i]);
			newstruct = ft_get_symb(str, argv[i], lengthfl);
			testbsq(str, newstruct);
			if (i + 1 < argc)
				ft_putchar('\n');
			i++;
		}
	}
	if (argc == 1)
	{
		get_consol_data();
	}
}

char	**ft_split(char *buf, int len, int k)
{
	char	**str;
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 0;
	str = (char**)malloc(sizeof(char *) * (k + 1));
	str[i] = (char*)malloc(sizeof(char) * (len + 1));
	while (i < k)
	{
		if (buf[m] == '\n')
		{
			str[i][j] = buf[m];
			str[i][j + 1] = '\0';
			i++;
            m++;
			str[i] = (char*)malloc(sizeof(char) * (j + 2));
			j = 0;
		}
		str[i][j] = buf[m];
		m++;
		j++;
	}
	return (str);
}

void	get_consol_data(void)
{
	struct s_get_data_cons	newdata;
	char					**str1;
	int						lengthfl;
	struct s_info			newstruct;

	newdata.k = 0;
	newdata.i = 0;
	newdata.len = 0;
	while (read(0, &newdata.buf[newdata.i], 1) != 0)
		newdata.i++;
	while (newdata.buf[newdata.len] != '\n')
		newdata.len++;
	newdata.i = 0;
	while (newdata.buf[newdata.i] != '\0')
	{
		if (newdata.buf[newdata.i] == '\n')
		{
			newdata.k++;
		}
		newdata.i++;
	}
	str1 = ft_split(newdata.buf, newdata.len, newdata.k);
	lengthfl = get_firstline_length2(str1);
	newstruct = ft_get_symb2(str1, lengthfl, newdata);
	testbsq(str1, newstruct);
}

int		ft_del_num(int nbr, int razn)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (i != razn)
	{
		res = nbr % 10;
		nbr = (nbr - res) / 10;
		i++;
	}
	return (nbr);
}
