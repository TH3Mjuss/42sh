/*
** parser_tok.c for 42sh in /home/gysc0/rendu/my_42/Sources/parser
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Sun May 11 17:51:56 2014 Zackary Beaugelin
** Last update Sun May 25 01:10:06 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_counttok(char *str)
{
  int	i;
  int	nb_cmd;

  i = 0;
  nb_cmd = 2;
  while (str[i] && str[i] != '\n')
    {
      if (!my_tk_chk(str + i))
        nb_cmd++;
      i++;
    }
  return (nb_cmd);
}

int	my_count_ctok(char *str)
{
  int	c;

  c = 0;
  while (my_tk_chk(str + c) && str[c] && str[c] != '\n')
    c++;
  c++;
  return (c);
}

int	check_not_tok(char *str, int i)
{
  while (str[i] && !my_tk_chk(str + i))
    i++;
  return (i);
}

char	**tok_to_tab(char *str, int j, int k)
{
  int	i;
  char	**tab;

  i = check_not_tok(str, 0);
  tab = xmalloc(sizeof(char *) * my_counttok(str));
  while (str[i] != '\n' && str[i])
    {
      if (!my_tk_chk(str + i) || str[i] == '\n')
        {
	  while (str[i] && !my_tk_chk(str + i))
            i++;
          j++;
          k = 0;
        }
      tab[j] = xmalloc(sizeof(char) * (my_count_ctok(str + i)));
      while (my_tk_chk(str + i) && str[i] != '\n' && str[i])
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
    }
  tab[j] = NULL;
  return (tab);
}
