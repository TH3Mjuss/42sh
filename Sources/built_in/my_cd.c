/*
** my_cd.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:10:41 2014 Zackary Beaugelin
** Last update Tue May  6 16:45:11 2014 Gysc0
*/

#include "my_sh.h"

char	*my_find(char **env, int k, char *to_find)
{
  char	**directory;
  char	*dir_ret;

  while (env[k])
    {
      if (my_strncmp(to_find, env[k], my_strlen(to_find)) == 0)
	{
	  directory = my_str_to_wordtab(env[k], '\n', 0);
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
