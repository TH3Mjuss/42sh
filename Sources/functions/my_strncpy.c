/*
** my_strncpy.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:17:11 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:17:22 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n < i)
    {
      dest[i] = '\0';
    }
  return (dest);
}
