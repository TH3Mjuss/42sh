/*
** my_echo2.c for my_echo2 in /home/Galendder/42sh/42sh/Sources/built_in
** 
** Made by Cedric Sanchez
** Login   <sanche_c@epitech.net>
** 
** Started on  Fri May  9 09:48:27 2014 Cedric Sanchez
** Last update Sun May 11 18:47:20 2014 Cedric Sanchez
*/

#include "my_sh.h"

int	checkopt(char **tab, int y, int x)
{
  int	check;
  int	check2;

  check2 = 0;
  check = 0;
  while (tab[1][y])
    {
      if (tab[1][y] == 'e')
	{
	  check = eoption(tab[x]);
	  check2 = 1;
	}
      if (tab[1][y] == 'n' || check2 != 1)
	{
	  check = 1;
	  my_putstr(tab[x], 1);
	}
      y++;
    }
  return (check);
}

char	*inittab2()
{
  char *tab;

  tab = xmalloc(sizeof(char) * 11);
  tab[0] = '\\';
  tab[1] = '\a';
  tab[2] = '\b';
  tab[3] = 'c';
  tab[4] = '\e';
  tab[5] = '\f';
  tab[6] = '\n';
  tab[7] = '\r';
  tab[8] = '\t';
  tab[9] = '\v';
  tab[10] = '\0';
  return (tab);
}
