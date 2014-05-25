/*
** my_cd.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:10:41 2014 Zackary Beaugelin
** Last update Sun May 25 21:51:33 2014 lennuy_f
*/

#include "my_sh.h"

char	*my_find(char **env, int k, char *to_find)
{
  char	**directory;
  char	*dir_ret;

  if (env)
    while (env[k])
      {
	if (my_strncmp(to_find, env[k], my_strlen(to_find)) == 0)
	  {
	    directory = my_str_to_wordtab(env[k], '\n', 0, 0);
	    dir_ret = xmalloc(my_strlen(directory[0]));
	    dir_ret = directory[0];
	    return (dir_ret);
	  }
	k++;
      }
  return (NULL);
}

char	**my_cd_tiray(char *dir, char **env)
{
  if (!(dir = my_find(env, 0, "OLDPWD")))
    {
      my_putstr("42sh: cd: OLDPWD not set\n", 2);
      return (env);
    }
  chdir(dir);
  env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
  env = my_setenv(env, "PWD", dir);
  my_putstr(dir, 1);
  my_putchar('\n');
  return (env);
}

void	my_cd_error(char **param, int x)
{
  my_putstr("42sh: cd: ", 2);
  if (x == 1)
    my_putstr("~/", 1);
  my_putstr(param[1], 2);
  my_putstr(": No such file or directory\n", 2);
}

char	**my_cd_homer(char *dir, char **env, char **param, char *buff)
{
  env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
  dir = my_find(env, 0, "HOME");
  chdir(dir);
  param[1] += 2;
  if (chdir(param[1]) != -1)
    env = my_setenv(env, "PWD", getcwd(buff, 4096));
  else
    my_cd_error(param, 1);
  return (env);
}

char	**my_cd(char **param, char **env)
{
  char  *dir;
  char	buff[4096];

  dir = NULL;
  if (param[1] == NULL || my_strcmp(param[1], "~") == 0
      || my_strcmp(param[1], "~/") == 0)
    {
      env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
      dir = my_find(env, 0, "HOME");
      chdir(dir);
      env = my_setenv(env, "PWD", dir);
    }
  else if (my_strncmp(param[1], "~/", 2) == 0)
    env = my_cd_homer(dir, env, param, buff);
  else if (my_strcmp(param[1], "-") == 0)
    env = my_cd_tiray(dir, env);
  else if (chdir(param[1]) != -1)
    {
      env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
      env = my_setenv(env, "PWD", getcwd(buff, 4096));
    }
  else
    my_cd_error(param, 0);
  return (env);
}
