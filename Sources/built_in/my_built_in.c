/*
** my_built_in.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:09:35 2014 Zackary Beaugelin
** Last update Tue May  6 16:43:35 2014 Gysc0
*/

#include "my_sh.h"

void	my_env(char **cur_env, char **param)
{
  int	k;

  k = 0;
  if (param[1] == NULL)
    while (cur_env[k])
      {
	my_putstr(cur_env[k], 1);
	write(1, "\n", 1);
	k++;
      }
  else if (my_strcmp(param[1], "-0") == 0
	   || my_strcmp(param[1], "--null") == 0)
    while (cur_env[k])
      {
	my_putstr(cur_env[k], 1);
	k++;
      }
  else if ((my_strcmp(param[1], "-i") == 0
	   || my_strcmp(param[1], "--ignore-environment") == 0)
	   && param[2] == NULL)
    write (1, "\n", 1);
  else if (my_strcmp(param[1], "-u") == 0)
    my_unsetenv(param[2], cur_env);
}

char    *added_str(char *name, char *var)
{
  char  *added;

  added = my_strcat(name, "=");
  added = my_strcat(added, var);
  return (added);
}

void	my_setenv_bis(int i, t_mysh *ms, char **cp_env, char **add_env)
{
  if (my_strncmp(ms->name, cp_env[i], my_strlen(ms->name)) == 0)
    add_env[i] = ms->str_add;
  else if (cp_env[i + 1] == NULL)
    {
      add_env[i] = cp_env[i];
      i = i + 1;
      add_env[i] = ms->str_add;
      add_env[i + 1] = NULL;
    }
  else
    add_env[i] = cp_env[i];
}

char		**my_setenv(char **cp_env, char *name, char *var)
{
  int		lenght;
  int		i;
  t_mysh	ms;
  char		**add_env;

  i = 0;
  lenght = 0;
  ms.name = name;
  ms.val = var;
  ms.str_add = added_str(name, var);
  while (cp_env[lenght] != NULL)
    lenght++;
  add_env = xmalloc((lenght + 2) * sizeof(char *));
  while (i != lenght)
    {
      my_setenv_bis(i, &ms, cp_env, add_env);
      i++;
    }
  return (add_env);
}

char	**my_unsetenv(char *name, char **environ)
{
  char	**cpy_env;
  int	k;
  int	i;
  int	lenght;
  char	**save_env;

  k = 0;
  i = 0;
  lenght = 0;
  cpy_env = environ;
  if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL)
    return (cpy_env);
  while (cpy_env[lenght] != NULL)
    lenght++;
  save_env = xmalloc((lenght - 1) * sizeof(char *));
  while (cpy_env[k])
    if (my_strncmp(cpy_env[k], name, my_strlen(name)) == 0)
      k++;
    else
      {
	save_env[i] = cpy_env[k];
	k++;
	i++;
      }
  return (save_env);
}
