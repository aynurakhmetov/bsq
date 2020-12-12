#include "list.h"

int		get_lines_in_crypt(char **matr, int lengthofline)
{
	int cryptleng;
	int dl;
	int dlnum;
	int otn;

	dl = lengthofline - 3;
	cryptleng = ft_atoi(matr[0]);
	dlnum = ft_leng_nbr(cryptleng);
	if (dl == dlnum)
		return (cryptleng);
	else if (dlnum > dl)
	{
		otn = dlnum - dl;
		return (ft_del_num(cryptleng, otn));
	}
	else
		return (-1);
}

char	**get_matrix(int columns, int lines, char *filename, int col)
{
	int		fd;
	int		i;
	int		j;
	char	**matrix;
	char	buf[1];

	matrix = (char**)malloc(sizeof(char *) * (lines + 1));
	i = 0;
	j = 0;
	fd = open(filename, O_RDONLY);
	matrix[i] = (char*)malloc(sizeof(char) * (columns + 2));
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
		{
			matrix[i][j] = buf[0];
			matrix[i][j + 1] = '\0';
			i++;
			if (i == 1)
				matrix[i] = (char*)malloc(sizeof(char) * (col + 2));
			else
				matrix[i] = (char*)malloc(sizeof(char) * (j + 2));
			j = 0;
			continue;
		}
		matrix[i][j] = buf[0];
		j++;
	}
	close(fd);
	return (matrix);
}

int		get_lines(char *filename)
{
	int		i;
	char	buf[1];
	int		fd;
	int		lines;

	i = 0;
	lines = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			lines++;
		i++;
	}
	close(fd);
	return (lines);
}

int		get_firstline_length(char *filename)
{
	int		countn;
	int		i;
	char	buf[1];
	int		fd;
	int		firstn;

	i = 0;
	countn = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n' && countn == 0)
		{
			firstn = i;
			countn++;
			continue;
		}
		i++;
	}
	close(fd);
	return (firstn);
}

int		get_column_length(char *filename)
{
	int		countn;
	int		i;
	char	buf[1];
	int		fd;
	int		column;

	i = 0;
	countn = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
		{
			countn++;
			i = 0;
			continue;
		}
		if (countn == 1)
			column = i;
		i++;
	}
	close(fd);
	return (column + 1);
}
