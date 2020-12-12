#include "list.h"

struct	s_info		ft_get_symb(char **matr, char *filename, int lengthofline)
{
	struct s_info	getsymb;

	getsymb.strinquad = get_lines(filename);
	getsymb.len = get_column_length(filename);
	getsymb.strok = get_lines_in_crypt(matr, lengthofline);
	getsymb.bas = get_void_num(matr, lengthofline);
	getsymb.let = get_obstacle(matr, lengthofline);
	getsymb.re = get_agregate(matr, lengthofline);
	return (getsymb);
}

int					ft_atoi(char *str)
{
	int		mn[3];

	mn[0] = 0;
	mn[1] = 0;
	mn[2] = 0;
	while (*str == '\r' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == ' ' || *str == '\f' || *str == '+')
	{
		str = str + 1;
	}
	if (*str == '-')
	{
		mn[2] = 1;
		str++;
	}
	while (str[mn[1]] >= 48 && str[mn[1]] <= 57)
	{
		mn[0] = mn[0] * 10 + (str[mn[1]] - 48);
		mn[1]++;
	}
	if (mn[2] == 1)
		return (-mn[0]);
	return (mn[0]);
}

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
