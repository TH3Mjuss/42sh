/*
** my_echo.c for my_echo in /home/Galendder/42sh/42sh
** 
** Made by Cedric Sanchez
** Login   <sanche_c@epitech.net>
** 
** Started on  Tue May  6 15:31:46 2014 Cedric Sanchez
** Last update Fri May 23 18:46:27 2014 lennuy_f
*/

#include "my_sh.h"

char	*inittab()
{
  char	*tab;

  tab = xmalloc(sizeof(char) * 11);
  tab[0] = '\\';
  tab[1] = 'a';
  tab[2] = 'b';
  tab[3] = 'c';
  tab[4] = 'e';
  tab[5] = 'f';
  tab[6] = 'n';
  tab[7] = 'r';
  tab[8] = 't';
  tab[9] = 'v';
  tab[10] = '\0';
  return (tab);
}

void	my_echo(char **tab)
{
  int	check;

  check = 1;
  if (tab[2] == NULL || tab[1][0] != '-')
    {
      my_putstr(tab[1], 1);
      my_putchar(' ');
    }
  else
    check = testopt(tab, 2);
  if (check == 1)
    my_putchar('\n');
}

int	testopt(char **tab, int x)
{
  int	check;
  int	check2;

  check = 0;
  check2 = 0;
  while (tab[x])
    {
      if (tab[1][0] == '-')
	{
	  check = checkopt(tab, 1, x);
	}
      else
	my_putstr(tab[x], 1);
      if (tab[x + 1])
	my_putchar(' ');
      x++;
    }
  if (check2 == 0 && check == 0)
    return (1);
  else
    return (0);
}

int	checkslash(char *tab, char *tab2, char *str, int i)
{
  int	j;

  j = 0;
  while (tab[j] != str[i] && tab[j] != '\0')
    {
      if (tab[j] == str[i])
	{
	  if (j == 3)
	    return (1);
	  else
	    {
	      my_putchar(tab2[j]);
	    }
	}
      j++;
    }
  return (0);
}

int	eoption(char *str)
{
  int	i;
  char *tab;
  int	check2;
  char	*tab2;

  check2 = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	{
	  tab = inittab();
	  tab2 = inittab2();
	  check2 = checkslash(tab, tab2, str, i);
	  free(tab);
	  free(tab2);
	}
      else
	my_putchar(str[i]);
      i++;
      if (str[i - 1] == '\\')
	i++;
    }
  return (check2);
}
