/*
** my_strcat.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:14:56 2014 Zackary Beaugelin
** Last update Tue Apr 22 16:08:20 2014 Cedric Sanchez
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

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	k;
  int	lenght;
  char	*ret;

  i  = 0;
  k = my_strlen(str1);
  lenght = my_strlen(str2) + k;
  ret = xmalloc(sizeof(char) * lenght + 1);
  while (i != k)
    {
      ret[i] = str1[i];
      i += 1;
    }
  i = 0;
  while ((k + i) != lenght)
    {
      ret[k + i] = str2[i];
      i += 1;
    }
  ret[k + i] = '\0';
  return (ret);
}
