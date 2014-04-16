/*
** my_strcpy.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:15:54 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:16:08 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i + 1] = '\0';
  return (dest);
}
