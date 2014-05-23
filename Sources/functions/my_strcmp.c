/*
** my_strcmp.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:15:28 2014 Zackary Beaugelin
** Last update Wed May 21 18:17:52 2014 jussea_m@epitech.eu
*/

#include "my_sh.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i = i + 1;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
