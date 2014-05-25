/*
** minishell.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:09:17 2014 Zackary Beaugelin
** Last update Sun May 25 22:41:29 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	**g_env;
int	g_test;

void		my_prompt()
{
  char	hostname[1024];
  char	buff[512];

  hostname[1023] = '\0';
  gethostname(hostname, 1023);
  if (!my_putstr(my_find(g_env, 0, "USER="), 1))
    my_putstr("user", 1);
  my_putstr("@", 1);
  my_putstr(hostname, 1);
  my_putstr(" \e[32m", 1);
  my_putstr(getcwd(buff, 512), 1);
  my_putstr("\e[0m> ", 1);
}

void	init_minishell(int ac, char **av, char **cp_env)
{
  system("clear");
  my_putstr("\e[36m", 1);
  my_putstr("    _____                 _      _ _____ _   _\n", 1);
  my_putstr("   |  _  |               | |    (_)  ___| | | |\n", 1);
  my_putstr("   | | | |_   _  __ _  __| |_ __ _\\ `--.| |_| |\n", 1);
  my_putstr("   | | | | | | |/ _` |/ _` | \'__| |`--. \\  _  |\n", 1);
  my_putstr("   \\ \\/\' / |_| | (_| | (_| | |  | /\\__/ / | | |\n", 1);
  my_putstr("    \\_/\\_\\\\__,_|\\__,_|\\__,_|_|  |_\\____/\\_| |_/\n", 1);
  my_putstr("\e[0m", 1);
  my_putstr("made by: beauge_z - jussea_m - lennuy_f - sanche_c\n\n", 1);
  g_env = cp_env;
  if (ac != 1 || av[1])
    exit(write(2, "Just launch it !\n", 17));
}

void    my_signal(int sig)
{
  if (sig == SIGINT)
    {
      write (1, "\n", 1);
      my_prompt();
    }
}

int	my_parser(char **wordtab, int i, char **env)
{
  if (!wordtab)
    return (i);
  else if (!my_strcmp(wordtab[0], "help"))
    i = my_help();
  else if (!my_strcmp(wordtab[0], "cd"))
    g_env = my_cd(wordtab, env);
  else if (!my_strcmp(wordtab[0], "env"))
    my_env(env, wordtab);
  else if (!my_strcmp(wordtab[0], "setenv"))
    g_env = my_setenv(env, wordtab[1], wordtab[2]);
  else if (!my_strcmp(wordtab[0], "unsetenv"))
    g_env = my_unsetenv(wordtab[1], g_env);
  else if (!my_strcmp(wordtab[0], "echo"))
    my_echo(wordtab);
  else if (!my_strncmp(wordtab[0], "exit", 5))
    {
      g_test = 0;
      i = my_exit(wordtab);
    }
  else
    i = my_execve(wordtab, g_env);
  return (i);
}

int	main(int ac, char **av, char **env)
{
  int	k;
  int	i;
  char	*buffer;

  init_minishell(ac, av, env);
  g_test = 1;
  while (g_test == 1)
    if (signal(SIGINT, my_signal) == SIG_ERR)
      exit(-1);
    else
      {
	i = -1;
	my_prompt();
	buffer = xmalloc(sizeof(char) * 4096);
	while (++i < 4096)
	  buffer[i] = 0;
	xread(0, buffer, 4096);
	k = my_preparser(cmd_to_tab(my_epur_str(buffer), 0, 0),
			 tok_to_tab(buffer, 0, 0), g_env);
      }
  return (k);
}
