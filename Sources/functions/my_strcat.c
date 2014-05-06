/*
** my_strcat.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:14:56 2014 Zackary Beaugelin
** Last update Wed Apr 23 13:14:28 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_strlen(char *str)
{
  int	k;

  k = 0;
  if (str == NULL)
    return (0);
  else
    while (str[k])
      k++;
  return (k);
}

char	*my_strcat(char *str1, char *str2, t_bfree *bf)
{
  int	i;
  int	k;
  int	lenght;

  i  = 0;
  k = my_strlen(str1);
  lenght = my_strlen(str2) + k;
  bf->ret = xmalloc(sizeof(char) * lenght + 1);
  while (i != k)
    {
      bf->ret[i] = str1[i];
      i += 1;
    }
  i = 0;
  while ((k + i) != lenght)
    {
      bf->ret[k + i] = str2[i];
      i += 1;
    }
  bf->ret[k + i] = '\0';
  return (bf->ret);
}
