/*
** my_putstr.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:13:24 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:13:27 2014 Zackary Beaugelin
*/

#include "my_sh.h"

void	my_putstr(char *str, int fd)
{
  if (str == NULL)
    my_putstr("(null)\n", 2);
  else
    write(fd, str, my_strlen(str));
}
