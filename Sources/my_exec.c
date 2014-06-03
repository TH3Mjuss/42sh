/*
** my_exec.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:11:24 2014 Zackary Beaugelin
** Last update Mon Jun  2 21:00:59 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	g_check;

void	sig_handler(int sig)
{
  if (sig == SIGSEGV)
    my_putstr("QuadriSH: Segmentation fault (core dumped)\n", 2);
}

void	my_exec_bis(t_exec *e, char *path, char **param, char **env)
{
  e->pid = fork();
  if (e->pid < 0)
    return ;
  if (e->pid == 0)
      execve(path, param, env);
  else
    {
      signal(SIGSEGV, sig_handler);
      waitpid(e->pid, &e->status, 0);
    }
  g_check = 0;
}

int		my_exec(char **bin, char **param, char **env, int k)
{
  t_exec	e;

  if (!access(param[0], X_OK) && g_check)
    my_exec_bis(&e, param[0], param, env);
  if (bin)
    {
      if (bin[k])
	e.path = my_strcat(bin[k], "/");
      else if (!bin[k])
	e.path = my_strcat("\0", "./");
      e.path = my_strcat(e.path, param[0]);
      if (access(e.path, X_OK) == -1 && !(bin[k + 1]) && g_check)
	{
	  my_putstr(param[0], 2);
	  my_putstr(": command not found\n", 2);
	  return (0);
	}
      else if (!access(e.path, X_OK) && g_check)
	{
	  my_exec_bis(&e, e.path, param, env);
	  return (e.status);
	}
   }
  return (1);
}

int	my_execve(char **param, char **env)
{
  char	**bin;
  int	k;
  int	ret;

  k = 0;
  ret = 1;
  bin = my_str_to_wordtab(my_find(env, 0, "PATH"), ':', 0, 0);
  g_check = 1;
  if (!bin && access(param[0], X_OK))
    {
      if (!param[0])
	return (0);
      my_putstr(param[0], 2);
      my_putstr(": command not found\n", 2);
      return (0);
    }
  while ((bin || !access(param[0], X_OK)) && g_check && ret)
    {
      ret = my_exec(bin, param, env, k);
      k++;
    }
  return (ret);
}
