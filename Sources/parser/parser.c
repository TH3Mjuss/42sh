/*
** parser.c for 42sh in /home/gysc0/rendu/my_42/Sources/parser
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Wed May  7 16:23:42 2014 Zackary Beaugelin
** Last update Tue May 13 20:13:50 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_tk_chk(char *str)
{
  int	i;
  char	*gtok[] = {"&&", "&", "||", "|", ";", "<<", "<", ">>", ">", NULL};

  i = -1;
  while (gtok[++i])
    if (!my_strncmp(str, gtok[i], my_strlen(gtok[i])))
      return (1);
  return (0);
}

int	my_countcmd(char *str)
{
  int	i;
  int	nb_cmd;

  i = 0;
  nb_cmd = 2;
  while (str[i] && str[i] != '\n')
    {
      if (my_tk_chk(str + i))
	nb_cmd++;
      i++;
    }
  return (i);
}

int	my_countc(char *str)
{
  int	c;

  c = 0;
  while (my_tk_chk(str + c) && str[c] && str[c] != '\n')
    c++;
  c++;
  return (c);
}

int	check_tok(char *str, int i)
{
  if (my_tk_chk(str + i) && str[i])
    while (my_tk_chk(str + i))
      i++;
  return (i);
}

char	**cmd_to_tab(char *str, int j, int k)
{
  int	i;
  char	**tab;

  i = check_tok(str, 0);
  tab = xmalloc(sizeof(char *) * my_countcmd(str));
  while (str[i] != '\n' && str[i])
    {
      if (my_tk_chk(str + i) || str[i] == '\n')
	{
	  while (my_tk_chk(str + i))
	    i++;
	  j++;
	  k = 0;
	}
      tab[j] = xmalloc(sizeof(char) * (my_countc(str + i)));
      while (!my_tk_chk(str + i) && str[i] != '\n' && str[i])
        tab[j][k++] = str[i++];
      tab[j][k] = '\0';
    }
  tab[j + 1] = NULL;
  return (tab);
}
