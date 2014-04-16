/*
** my_strncmp.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:16:29 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:16:50 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  while (n > 0)
    {
      if (*s1 != *s2)
	return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
      else if (*s1 == '\0')
	return 0;
      s1++;
      s2++;
      --n;
    }
  return (0);
}
