/*
** my_setold_pwd.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Sun May 18 17:32:33 2014 Zackary Beaugelin
** Last update Sun May 18 18:59:54 2014 lennuy_f
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

char	*my_setop(char *pwd, const char *point)
{
  int	i;

  i = 0;
  while (!my_strncmp((char *)point, "..", 2))
    {
      point = point + 2;
      if (*point == '/')
	point++;
      i++;
    }
  my_revstr(pwd);
  while (i > 0 && *pwd)
    {
      if (*pwd == '/')
	{
	  pwd++;
	  i--;
	}
      pwd++;
    }
  pwd--;
  my_revstr(pwd);
  if (*point)
    pwd = my_strcat(pwd, my_strcat("/", (char *)point));
  return (pwd);
}
