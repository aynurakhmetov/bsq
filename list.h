#ifndef LIST_H
# define LIST_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 4000

struct				s_sqrdo
{
	int				i;
	int				j;
	int				a;
}					;

struct				s_info
{
	int				len;
	int				strok;
	int				strinquad;
	char			bas;
	char			let;
	char			re;
}					;

struct				s_get_data_cons
{
	char			buf[BUF_SIZE];
	int				k;
	int				i;
	int				len;
}					;

typedef	struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char *str);
int					sideinstr(char **str, int i, int j, struct s_info xl);
int					width(char **str, int i, int j, struct s_info xl);
int					side(char **str, int i, int j, struct s_info xl);
struct s_sqrdo		findsqr(int w, int s, int i, int j);
void				printsqr(struct s_sqrdo m, char **str, struct s_info xl);
void				msqr(char **str, struct s_info xl);
int					testsimb(char **str);
int					test0(struct s_info a);
int					teststst(struct s_info a);
int					test0str(char **str, struct s_info a);
int					testcol(char **str, struct s_info a);
void				testbsq(char **str, struct s_info a);
void				print_list(t_list *list);
char				**ft_get_file(char *filename);
int					get_firstline_length(char *filename);
int					get_column_length(char *filename);
int					get_lines(char *filename);
char				**get_matrix(int columns,
		int lines, char *filename, int col);
struct s_info		ft_get_symb(char **matr, char *filename, int lengthofline);
int					get_lines_in_crypt(char **matr, int lengthofline);
char				get_void_num(char **matr, int lengthofline);
char				get_obstacle(char **matr, int lengthofline);
char				get_agregate(char **matr, int lengthofline);
int					ft_leng_nbr(int nbr);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
char				**ft_split(char *buf, int len, int k);
void				get_consol_data();
int					ft_del_num(int nbr, int razn);
int					get_firstline_length2(char **str);
struct s_info		ft_get_symb2(char **str,
		int lengthifline, struct s_get_data_cons newdata);
int					get_length2(char **str);

#endif
