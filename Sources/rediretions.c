/*
** test.c for test in /home/jussea_m
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Sun May 11 14:12:05 2014 jussea_m@epitech.eu
** Last update Sun May 25 21:09:07 2014 jussea_m@epitech.eu
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

void	prompt_dlr(t_redir *r, char *buff, char *stop)
{
  while (my_strncmp(buff, stop, my_strlen(stop)))
    {
      my_putstr("> ", 1);
      xread(0, buff, 4096);
      if (my_strncmp(buff, stop, my_strlen(stop)))
	write(r->file, buff, my_strlen(buff));
    }
}

int		my_dlr(char **param, char **param2, char **env)
{
  char		tmp[] = "/tmp/42sh";
  char		*file[] = {tmp, NULL};
  char		buff[4096];
  t_redir	r;

  r.file = open(tmp, O_WRONLY | O_TRUNC | O_CREAT, 0660);
  if (param2)
    {
      prompt_dlr(&r, buff, param2[0]);
      my_lr(param, file, env);
    }
  close(r.file);
  return (1);
}
