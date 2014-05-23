/*
** test.c for test in /home/jussea_m
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Sun May 11 14:12:05 2014 jussea_m@epitech.eu
** Last update Fri May 23 17:06:11 2014 jussea_m@epitech.eu
*/

#include "my_sh.h"

int	right_redirection(char **param, char **param2, char **env)
{
  int	file;
  int	pid;
  int	status;

  if (param2)
    {
      if ((file = open(param2[0], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR
		       | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((pid = fork()) < 0)
	return (1);
      if (pid == 0)
	{
	  dup2(file, 1);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(pid, &status, 0);
	  close(file);
	}
      return (1);
    }
  return (1);
}

int	double_right_redirection(char **param, char **param2, char **env)
{
  int	file;
  int	pid;
  int	status;

  if (param2)
    {
      if ((file = open(param2[0], O_WRONLY | O_APPEND, S_IRUSR
		       | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((pid = fork()) < 0)
	return (1);
      if (pid == 0)
	{
	  dup2(file, 1);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(pid, &status, 0);
	  close(file);
	}
      return (1);
    }
  return (1);
}

int	left_redirection(char **param, char **param2, char **env)
{
  int	file;
  int	pid;
  int	status;

  if (param2)
    {
      if ((file = open(param2[0], O_RDONLY) == -1)
	{
	  my_putstr("Cant't use file\n", 2);
	  return (1);
	}
      if ((pid = fork()) < 0)
	return (1);
      if (pid == 0)
	{
	  dup2(0, file);
	  my_parser(param, 1, env);
	  exit(0);
	}
      else
	{
	  waitpid(pid, &status, 0);
	  close(file);
	}
      return (1);
    }
  return (1);
}

