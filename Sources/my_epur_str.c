/*
** my_epur_str.c for my_epur_str.c in /home/jussea_m
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Tue May 13 14:50:34 2014 jussea_m@epitech.eu
** Last update Sun May 25 01:45:26 2014 Zackary Beaugelin
*/

#include "my_sh.h"

static void	check_for_tab(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
}

static void	epur_area(char *str, int i)
{
  int		j;

  j = i;
  while (str[++j] == ' ')
    ;
  while (str[j])
    str[i++] = str[j++];
  str[i] = 0;
}

char	*my_epur_str(char *str)
{
  int	i;

  i = -1;
  if (str == NULL || !*str)
    return (NULL);
  check_for_tab(str);
  epur_area(str, i);
  while (str[++i])
    if (str[i] == ' ' && str[i + 1] != 0)
      epur_area(str, i + 1);
  if (str[i - 1] == ' ')
    i--;
  str[i] = 0;
  return (str);
}
