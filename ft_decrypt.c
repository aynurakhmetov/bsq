#include "list.h"

int		ft_leng_nbr(int nbr)
{
	int		i;
	int		res;

	res = 1;
	i = 0;
	while (res != 0)
	{
		res = nbr % 10;
		nbr = (nbr - res) / 10;
		i++;
	}
	return (i - 1);
}

char	get_void_num(char **matr, int lengthofline)
{
	char	cvoid;

	cvoid = matr[0][lengthofline - 3];
	return (cvoid);
}

char	get_obstacle(char **matr, int lengthofline)
{
	char	cobstacle;

	cobstacle = matr[0][lengthofline - 2];
	return (cobstacle);
}

char	get_agregate(char **matr, int lengthofline)
{
	char cagr;

	cagr = matr[0][lengthofline - 1];
	return (cagr);
}

char	**ft_get_file(char *filename)
{
	int		desc;
	int		col;
	int		line;
	char	**mat;

	desc = get_firstline_length(filename);
	col = get_column_length(filename);
	line = get_lines(filename);
	mat = get_matrix(desc, line, filename, col);
	return (mat);
}
