/*
** my_strchr.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:15:13 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:15:16 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	*my_strchr(const char *s, int c)
{
  const char ch = c;

  while (*s != ch)
    {
      if (*s == '\0')
	return 0;
      s++;
    }
  return ((char *)s);
}
