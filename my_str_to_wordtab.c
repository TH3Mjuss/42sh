/*
** my_str_to_wordtab.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:17:34 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:17:37 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_countword(char *str, char sep)
{
  int	i;
  int	m;

  i = 0;
  m = 2;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == sep)
	m++;
      i++;
    }
  return (m);
}
int	my_countchar(char *str, char sep)
{
  int	c;

  c = 0;
  while (str[c] != sep && str[c] != '\0' && str[c] != '\n')
    c = c + 1;
  c = c + 1;
  return (c);
}

int	check_sep(char *str, int i, char sep)
{
  while (str[i] && str[i] != '=')
    i++;
  if (str[i] == '=')
    i++;
  if (str[i] == '\0')
    i = 0;
  if (str[i] == sep)
    while (str[i] == sep)
      i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char sep, int a, int b)
{
  char	**tab;
  int	i;

  i = check_sep(str, 0, sep);
  tab = xmalloc(sizeof(*tab) * (my_countword(str, sep)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == sep || str[i] == '\n')
	{
	  while (str[i] == sep)
	    i++;
	  a++;
	  b = 0;
	}
      tab[a] = xmalloc(sizeof(**tab) * (my_countchar(str + i, sep)));
      while (str[i] != sep && str[i] != '\n' && str[i])
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = NULL;
  return (tab);
}
