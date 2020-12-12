#include "list.h"

int					get_firstline_length2(char **str)
{
	int		i;

	i = 0;
	while (str[0][i] != '\n')
	{
		i++;
	}
	return (i);
}

struct	s_info		ft_get_symb2(char **str,
		int lengthifline, struct s_get_data_cons newdata)
{
	struct s_info	getsymb;

	getsymb.strinquad = newdata.k;
	getsymb.len = get_length2(str);
	getsymb.strok = get_lines_in_crypt(str, lengthifline);
	getsymb.bas = get_void_num(str, lengthifline);
	getsymb.let = get_obstacle(str, lengthifline);
	getsymb.re = get_agregate(str, lengthifline);
	return (getsymb);
}

int					get_length2(char **str)
{
	int		i;

	i = 0;
	while (str[1][i] != '\0')
	{
		i++;
	}
	return (i - 2);
}
