/*
** my_help.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:12:26 2014 Zackary Beaugelin
** Last update Mon Apr  7 22:58:36 2014 Mehdi Jusseaume
*/

#include "my_sh.h"

int	my_help()
{
  write(1, "HELP of minishell1\n", 39);
  write(1, "Version 0.1.2\n", 14);
  write(1, "Features supported :\n", 21);
  write(1, "\t- all functions;\n", 18);
  write(1, "\t- built-in:\n", 13);
  write(1, "\t  - cd;\n", 9);
  write(1, "\t  - env;\n", 10);
  write(1, "\t  - setenv;\n", 13);
  write(1, "\t  - unsetenv;\n", 15);
  write(1, "\t  - exit\n", 10);
  write(1, "--END OF HELP--\n", 16);
  return (1);
}
