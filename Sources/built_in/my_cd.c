/*
** my_cd.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:10:41 2014 Zackary Beaugelin
** Last update Wed May 21 17:54:32 2014 lennuy_f
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
  else if (my_strcmp(param[1], "-") == 0)
    {
      if (!(dir = my_find(env, 0, "OLDPWD")))
	{
	  my_putstr("42sh: cd: OLDPWD not set", 2);
	  return (env);
	}
      chdir(dir);
      env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
      env = my_setenv(env, "PWD", dir);
    }
  else if (chdir(param[1]) != -1)
    {
      env = my_setenv(env, "OLDPWD", my_find(env, 0, "PWD"));
      env = my_setenv(env, "PWD", getcwd(buff, 4096));
    }
  else
    {
      my_putstr("my_sh: cd: ", 2);
      my_putstr(param[1], 2);
      my_putstr(": No such file or directory\n", 2);
      return (env);
    }
  return (env);
}
