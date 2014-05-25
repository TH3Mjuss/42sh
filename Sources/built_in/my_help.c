/*
** my_help.c for 42sh in /home/gysc0/rendu/PSU_2013_minishell2
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Mon Apr  7 20:12:26 2014 Zackary Beaugelin
** Last update Sun May 25 17:23:43 2014 Zackary Beaugelin
*/

#include "my_sh.h"

int	my_help()
{
  write(1, "HELP of 42sh made by beauge_z sanche_c jussea_m lennuy_f\n", 57);
  write(1, "Version 42.1337\n", 16);
  write(1, "Features supported :\n", 21);
  write(1, "\t- all functions;\n", 18);
  write(1, "\t- built-in:\n", 13);
  write(1, "\t  - cd;\n", 9);
  write(1, "\t  - env;\n", 10);
  write(1, "\t  - setenv;\n", 13);
  write(1, "\t  - unsetenv;\n", 15);
  write(1, "\t  - exit;\n", 11);
  write(1, "\t  - echo;\n", 12);
  write(1, "\t- > < >> <<\n", 13);
  write(1, "--END OF HELP--\n", 16);
  return (1);
}
