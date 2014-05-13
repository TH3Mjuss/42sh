/*
** my_preparser.c for 42sh in /home/gysc0/rendu/my_42
** 
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
** 
** Started on  Tue May 13 19:39:15 2014 Zackary Beaugelin
** Last update Tue May 13 20:10:08 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_preparser(char **cmd, char **tok)
{
  int	i;
  int	ret;
  int	j;

  j = 0;
  i = -1;
  ret = 0;
  if (!tok)
    ret = my_parser(my_str_to_wordtab(cmd[0], ' ', 0, 0), 1);
  else
    while (tok[++i])
      {
	if (!my_strcmp(tok[i], "&&"))
	  ret = my_parser(my_str_to_wordtab(cmd[j], ' ', 0, 0), 1);
	else if (!my_strcmp(tok[i], ";"))
	  ret = my_parser(my_str_to_wordtab(cmd[j], ' ', 0, 0), 1);
	else
	  {
	    my_putstr(tok[i], 2);
	    my_putstr(": token not yet supported\n", 2);
	  }
	j++;
      }
  return (ret);
}
