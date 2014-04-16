/*
** minishell.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:09:17 2014 Zackary Beaugelin
** Last update Mon Apr  7 23:02:39 2014 Mehdi Jusseaume
*/

#include "my_sh.h"

char	**g_env;
int	g_test;

void		my_prompt()
{
  static int	i = 1;

  my_putstr("[\e[4;31m", 1);
  my_putstr(my_find(g_env, 0, "USER="), 1);
  my_putstr("@minishell2\e[24;96m ", 1);
  my_putnbr(i);
  my_putstr("\e[0m]", 1);
  i++;
}

void	init_minishell(int ac, char **av, char **cp_env)
{
  g_env = cp_env;
  if (ac != 1 || av[1] != NULL)
    exit(write(2, "Just lauch it !\n", 16));
}

void    my_signal(int sig)
{
  if (sig == SIGINT)
    {
      write (1, "\n", 1);
      my_prompt();
    }
}

int	my_parser(char **wordtab, int i)
{
  if (wordtab[0] == NULL)
    return (i);
  else if (!my_strcmp(wordtab[0], "help"))
    i = my_help();
  else if (!my_strcmp(wordtab[0], "cd"))
    g_env = my_cd(wordtab, g_env);
  else if (!my_strcmp(wordtab[0], "env"))
    my_env(g_env, wordtab);
  else if (!my_strcmp(wordtab[0], "setenv"))
    g_env = my_setenv(g_env, wordtab[1], wordtab[2]);
  else if (!my_strcmp(wordtab[0], "unsetenv"))
    g_env = my_unsetenv(wordtab[1], g_env);
  else if (!my_strncmp(wordtab[0], "exit", 5))
    {
      g_test = 0;
      if (!wordtab[1])
	return (1);
      else
	return (my_getnbr(wordtab[1]));
    }
  else
    i = my_execve(wordtab, 0, g_env);
  return (i);
}

int	main(int ac, char **av, char **env)
{
  int	k;
  int	j;
  char	buffer[4096];
  char	**pars;
  char	**wordtab;

  init_minishell(ac, av, env);
  g_test = 1;
  while (g_test == 1)
    if (signal(SIGINT, my_signal) == SIG_ERR)
      exit(-1);
    else
      {
	j = -1;
	my_prompt();
	xread(0, buffer, 4096);
	pars = my_str_to_wordtab(buffer, ';', 0, 0);
	while (pars[++j])
	  {
	    wordtab = my_str_to_wordtab(pars[j], ' ', 0, 0);
	    k = my_parser(wordtab, 1);
	  }
      }
  return (k);
}
