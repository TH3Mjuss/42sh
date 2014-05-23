/*
** my_exit.c for 42sh in /home/lennuy_f/rendu/42sh/Sources/built_in
** 
** Made by lennuy_f
** Login   <lennuy_f@epitech.net>
** 
** Started on  Fri May 23 18:31:24 2014 lennuy_f
** Last update Fri May 23 18:36:48 2014 lennuy_f
*/

#include "my_sh.h"

int	my_exit(char **wordtab)
{
  my_putstr("exit\n", 1);
  if (!wordtab[1])
    return (0);
  else
    return (my_getnbr(wordtab[1]));
}
