/*
** my_cd.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:10:41 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:10:45 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	*my_find(char **env, int k, char *to_find)
{
  char	**directory;
  char	*dir_ret;

  dir_ret = xmalloc(sizeof(char) * 4096);
  while (env[k])
    {
      if (my_strncmp(to_find, env[k], my_strlen(to_find)) == 0)
	{
	  directory = my_str_to_wordtab(env[k], '\n', 0, 0);
	  dir_ret = directory[0];
	  return (dir_ret);
	}
      k++;
    }
  if (env[0] == NULL)
    return (NULL);
  else
    return (dir_ret);
}

char	**my_cd(char **param, char **env)
{
  char  *dir;

  if (param[1] == NULL || my_strcmp(param[1], "~") == 0
      || my_strcmp(param[1], "~/") == 0)
    {
      dir = my_find(env, 0, "HOME");
      chdir(dir);
    }
  else if (chdir(param[1]) == -1)
    {
      my_putstr("my_sh: cd: ", 2);
      my_putstr(param[1], 2);
      my_putstr(": No such file or directory\n", 2);
      return (env);
    }
  return (env);
}
