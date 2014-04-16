/*
** xmalloc.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
** 
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
** 
** Started on  Mon Apr  7 20:10:06 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:10:20 2014 Zackary Beaugelin
*/

#include "my_sh.h"

void	*xmalloc(int size)
{
  char	*tmp;

  if ((tmp = malloc(size)) == NULL)
    exit(-1);
  return (tmp);
}
