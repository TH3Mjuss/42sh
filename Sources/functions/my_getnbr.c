/*
** my_getnbr.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:11:39 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:11:41 2014 Zackary Beaugelin
*/


#include "my_sh.h"

int	is_neg(char *str)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        k = k + 1;
      i = i + 1;
    }
  if (k % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  double	nbr;

  nbr = 0;
  i = 0;
  if (str == '\0')
    return (0);
  while (is_num(str[i]) == 0)
    i = i + 1;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i = i + 1;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  if (nbr <= -2147483648 || nbr >= 2147483647)
    nbr = 0;
  return (nbr);
}
