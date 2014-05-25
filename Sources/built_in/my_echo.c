/*
** my_echo.c for my_echo.c in /home/Galendder/rendu/42sh/my_echo
** 
** Made by Cedric Sanchez
** Login   <sanche_c@epitech.net>
** 
** Started on  Sat May 24 17:32:21 2014 Cedric Sanchez
** Last update Sun May 25 16:34:10 2014 Cedric Sanchez
*/

#include "my_sh.h"

void    putspecchar(char c)
{
  if (c == 'a')
    my_putchar('\a');
  else if (c == '\\')
    my_putchar('\\');
  else if (c == 'b')
    my_putchar('\b');
  else if (c == 'e')
    my_putchar('\e');
  else if (c == 'f')
    my_putchar('\f');
  else if (c == 'n')
    my_putchar('\n');
  else if (c == 'r')
    my_putchar('\r');
  else if (c == 't')
    my_putchar('\t');
  else if (c == 'v')
    my_putchar('\v');
  else
    {
      my_putchar('\\');
      my_putchar(c);
    }
}

void    my_putstrecho(char *str, int check)
{
  int   i;

  i = 0;
  while (str[i])
    {
      while (str[i] == '"')
	i++;
      if (check >= 1 && str[i] == '\\')
	{
	  putspecchar(str[i + 1]);
          i++;
	}
      else if (check <= 0 && str[i] == '\\')
	{
	  my_putchar('\\');
	  my_putchar(str[i + 1]);
	  i++;
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

void     checkopt(char **tab, int x)
{
  int   y;
  int   check;
  int	checkn;

  check = 0;
  y = 0;
  checkn = 0;
  while (tab[x][y])
    {
      if (tab[x][y] == 'e')
	check++;
      else if (tab[x][y] == 'E')
	check = check - 1;
      else if (tab[x][y] == 'n')
	checkn = 1;
      y++;
    }
  x++;
  while (tab[x])
    {
      my_putstrecho(tab[x], check);
      x++;
    }
  if (checkn != 1)
    my_putchar('\n');
}

int	checkcmd(char **av, int x)
{
  while (av[x])
    {
      if (av[x][0] == '-' && av[x + 1][0] != '-' && av[x + 1] != NULL)
	  checkopt(av, x);
      else  if (av[x][0] == '-' && av[x + 1] != NULL && av[x + 1][0] == '-')
	x++;
      else if (av[x][0] == '-' && av[x + 1] == NULL)
	return (0);
      x++;
    }
  return (1);
}

int	my_echo(char **tab)
{
  int   x;

  x = 1;
  if (tab[1] == NULL)
    my_putchar('\n');
  else if (tab[1][0] != '-' || (tab[1][0] == '-' &&
				tab[1][1] == '\0'))
    {
      while (tab[x])
	{
	  my_putstrecho(tab[x], 0);
	  if (tab[x + 1] != NULL)
	    my_putchar(' ');
	  x++;
	}
      my_putchar('\n');
    }
  else
    {
      if (tab[x + 1] != NULL)
	checkcmd(tab, x);
    }
  return (0);
}
