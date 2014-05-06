/*
** my_str_to_wordtab.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:17:34 2014 Zackary Beaugelin
** Last update Wed Apr 23 13:19:02 2014 Zackary Beaugelin
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
  if (str[i] == '\0')
    i = 0;
  if (str[i] == '=')
    i++;
  if (str[i] == sep)
    while (str[i] == sep)
      i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char sep, int a, t_bfree *bf)
{
  int	i;
  int	b;

  b = 0;
  i = check_sep(str, 0, sep);
  bf->tab = xmalloc(sizeof(char *) * (my_countword(str, sep)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == sep || str[i] == '\n')
	{
	  while (str[i] == sep)
	    i++;
	  a++;
	  b = 0;
	}
      bf->tab[a] = xmalloc(sizeof(char) * (my_countchar(str + i, sep)));
      while (str[i] != sep && str[i] != '\n' && str[i])
	bf->tab[a][b++] = str[i++];
      bf->tab[a][b] = '\0';
    }
  bf->tab[a + 1] = NULL;
  return (bf->tab);
}
