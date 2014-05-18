/*
** my_setold_pwd.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Sun May 18 17:32:33 2014 Zackary Beaugelin
** Last update Sun May 18 17:55:08 2014 Zackary Beaugelin
*/

#include "my_sh.h"

char	*my_revstr(char *s)
{
  char *p = NULL;
  char temp;

  p = s;
  while (*p != '\0')
    p++;
  p--;
  while (s < p)
    {
      temp = *s;
      *s = *p;
      *p = temp;
      s++;
      p--;
    }
  p--;
  return (p);
}

char	*my_setop(char *pwd, char *point)
{
  int	i;
  char	*ret;

  i = 0;
  (const char *)point;
  while (my_strncmp(point, "..", 2))
    {
      point = point + 2;
      if (*point == '/')
	point++;
      i++;
    }
  ret = my_revstr(pwd);
  if (ret[0] == '/')
    ret++;
  while (i > 0 && *ret)
    {
      if (ret == '/')
	{
	  ret++;
	  i--;
	}
      ret++;
    }
  return (my_revstr(ret));
}
