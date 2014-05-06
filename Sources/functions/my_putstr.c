/*
** my_putstr.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:13:24 2014 Zackary Beaugelin
** Last update Wed Apr 23 12:51:59 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_putstr(char *str, int fd)
{
  if (str)
    return(write(fd, str, my_strlen(str)));
  return (0);
}
