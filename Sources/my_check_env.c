/*
** my_check_env.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Jun  2 07:33:30 2014 Zackary Beaugelin
** Last update Mon Jun  2 08:26:43 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_check_env(char **n_env, char **o_env)
{
  int	ret;
  int	i;
  int	k;

  i = 0;
  k = 0;
  ret = 0;
  if (n_env && o_env)
    while (n_env[i] && o_env[k] && !my_strcmp(n_env[i], o_env[k]))
      {
	i++;
	k++;
      }
  if (!n_env[i])
    ret = 0;
  return (ret);
}
