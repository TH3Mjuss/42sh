/*
** pipe.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Sun May 11 14:54:09 2014 Zackary Beaugelin
** Last update Tue Jun  3 01:57:35 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	exec_pipe(char **cmd, char **env)
{
  t_pip	p;

  p.ret = 0;
  if (pipe(p.fd) == -1)
    return (my_putstr("QuadriSH: Error pipe.\n", 2));
  if ((p.pid = fork()) < 0)
    return (1);
  if (p.pid == 0)
    {
      close(p.fd[0]);
      dup2(p.fd[1], 1);
      my_parser(my_str_to_wordtab(CMD(cmd[0])), 1, env);
      exit(0);
    }
  else
    {
      close(p.fd[1]);
      dup2(p.fd[0], 0);
      my_parser(my_str_to_wordtab(CMD(cmd[1])), 1, env);
      wait(&p.ret);
      exit(0);
    }
  return (p.ret);
}

int	my_pipe(char **cmd, char **env)
{
  int	pid;
  int	ret;

  ret = 0;
  if ((pid = fork()) < 0)
    return (1);
  if (pid == 0)
    {
      exec_pipe(cmd, env);
      exit(0);
    }
  else
    wait(&ret);
  return (ret);
}
