/*
** my_sh.h for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:14:03 2014 Zackary Beaugelin
** Last update Tue May  6 16:34:36 2014 Gysc0
*/

#ifndef __MY_SH__
# define __MY_SH__

#  include <unistd.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <sys/wait.h>
#  include <errno.h>
#  include <signal.h>

typedef struct	s_mysh
{
  char	*str_add;
  char	*name;
  char	*val;
}		t_mysh;

typedef struct	s_exec
{
  char	*path;
  pid_t	pid;
  int	status;
}		t_exec;

int	main(int ac, char **av, char **env);
int	my_execve(char **param, char **env);
char	*my_strcat(char *dest, char *src);
void	my_putchar(char c);
void	my_putnbr(int nb);
int	my_putstr(char *str, int fd);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *s1, char *s2);
void	*xmalloc(int size);
char	**my_str_to_wordtab(char *str, char sep, int a);
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

#endif /*__MY_SH__*/
