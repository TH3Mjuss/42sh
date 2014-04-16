/*
** xread.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:08:50 2014 Zackary Beaugelin
** Last update Mon Apr  7 20:08:53 2014 Zackary Beaugelin
*/

#include "my_sh.h"

void	xread(int fd, char *str, int lenght)
{
  if (read(fd, str, lenght) <= 0)
    {
      my_putstr("exit\n", 1);
      exit(0);
    }
}
