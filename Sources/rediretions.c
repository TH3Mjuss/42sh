/*
** test.c for test in /home/jussea_m
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Sun May 11 14:12:05 2014 jussea_m@epitech.eu
** Last update Fri May 23 19:48:26 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_rr(char **param, char **param2, char **env)
{
  t_redir	r;

  if (param2)
    {
      if ((r.file = open(param2[0], O_WRONLY | O_TRUNC | O_CREAT, 0660)) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((r.pid = fork()) < 0)
	return (1);
      if (r.pid == 0)
	{
	  dup2(r.file, 1);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(r.pid, &r.status, 0);
	  close(r.file);
	}
      return (1);
    }
  return (1);
}

int		my_drr(char **param, char **param2, char **env)
{
  t_redir	r;

  if (param2)
    {
      if ((r.file = open(param2[0], O_WRONLY | O_APPEND, 0660)) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((r.pid = fork()) < 0)
	return (1);
      if (r.pid == 0)
	{
	  dup2(r.file, 1);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(r.pid, &r.status, 0);
	  close(r.file);
	}
      return (1);
    }
  return (1);
}

int		my_lr(char **param, char **param2, char **env)
{
  t_redir	r;

  if (param2)
    {
      if ((r.file = open(param2[0], O_RDONLY)) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((r.pid = fork()) < 0)
	return (1);
      if (r.pid == 0)
	{
	  dup2(r.file, 0);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(r.pid, &r.status, 0);
	  close(r.file);
	}
      return (1);
    }
  return (1);
}

