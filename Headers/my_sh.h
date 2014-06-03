/*
** my_sh.h for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:14:03 2014 Zackary Beaugelin
** Last update Tue Jun  3 01:57:10 2014 Zackary Beaugelin
*/

#ifndef __MY_SH__
# define __MY_SH__

#  include <unistd.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#  include <stdlib.h>
#  include <sys/wait.h>
#  include <errno.h>
#  include <signal.h>
#  include <fcntl.h>
#  include <stdio.h>
#  include <pwd.h>

#   define CMD(cmd)	my_epur_str(cmd), ' ', 0, 0

typedef struct	s_mysh
{
  char	*str_add;
  char	*name;
  char	*val;
  int	test;
}		t_mysh;

typedef struct	s_exec
{
  char	*path;
  pid_t	pid;
  int	status;
}		t_exec;

typedef struct	s_parse
{
  int		i;
  int		j;
  int		ret;
}		t_parse;


typedef struct	s_redir
{
  int		file;
  int		pid;
  int		status;
}		t_redir;

typedef struct	s_pip
{
  int		ret;
  int		fd[2];
  int		pid;
  int		tmp;
}		t_pip;

int	main(int ac, char **av, char **env);
int	my_execve(char **param, char **env);
char	*my_strcat(char *dest, char *src);
void	my_putchar(char c);
void	my_putnbr(int nb);
int	my_putstr(char *str, int fd);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *s1, char *s2);
void	*xmalloc(int size);
char	**my_str_to_wordtab(char *str, char sep, int a, int b);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	is_num(char l);
int	is_neg(char *str);
int	my_help();
char	*my_find(char **env, int k, char *to_find);
char	**my_cd(char **param, char **env);
void	my_env(char **cur_env, char **param);
char	*my_strchr(const char *s, int c);
char    *my_strncpy(char *dest, char *src, int n);
int	my_strncmp(char *s1, char *s2, int n);
void	my_signal(int sig);
char	**my_setenv(char **cp_env, char *name, char *var);
char	**my_unsetenv(char *name, char **environ);
void	xread(int fd, char *str, int lenght);
int	my_echo(char **tab);
int	checkcmd(char **tab, int x);
void	my_putstrecho(char *str, int check);
void	checkopt(char **tab, int x);
void	putspecchar(char c);
char	**cmd_to_tab(char *str, int j, int k);
int	check_tok(char *str, int i);
int	my_countc(char *str);
int	my_countcmd(char *str);
int	my_tk_chk(char *str);
int	my_counttok(char *str);
int	my_count_ctok(char *str);
int	check_not_tok(char *str, int i);
char	**tok_to_tab(char *str, int j, int k);
int	my_preparser(char **cmd, char **tok, char **env);
int	my_parser(char **wordtab, int i, char **env);
int	my_rr(char **param, char **param2, char **env);
char	*my_epur_str(char *str);
int	my_countword(char *str, char sep);
int	my_countchar(char *str, char sep);
int	check_sep(char *str, int i, char sep);
char	**my_str_to_wordtab(char *str, char sep, int a, int b);
int     my_drr(char **param, char **param2, char **env);
int     my_lr(char **param, char **param2, char **env);
int	my_exit(char **wordtab);
void    prompt_dlr(t_redir *r, char *buff, char *stop);
int     my_dlr(char **param, char **param2, char **env);
int	my_check_env(char **n_env, char **o_env);
int	my_pipe(char **cmd, char **env);

#endif /*__MY_SH__*/
