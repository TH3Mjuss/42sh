/*
** my_exit.c for 42sh in /home/lennuy_f/rendu/42sh/Sources/built_in
** 
** Made by lennuy_f
** Login   <lennuy_f@epitech.net>
** 
** Started on  Fri May 23 18:31:24 2014 lennuy_f
** Last update Sun May 25 22:07:09 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_exit(char **wordtab)
{
  my_putstr("exit\n", 1);
  if (!wordtab[1])
    return (1);
  else
    return (my_getnbr(wordtab[1]));
}
