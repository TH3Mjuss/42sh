/*
** test.c for test in /home/jussea_m
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Sun May 11 14:12:05 2014 jussea_m@epitech.eu
** Last update Wed May 21 14:45:27 2014 jussea_m@epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	right_redirection(char **com, char **env)
{
  int	file;
  int	pid;
  int	tmp;
  int	stat;
  char	*tab;

  file = open(com[1], 0_WRONLY | 0_TRUNC | 0_CREAT, S_IRUSR 
	      | S_IRGRP | S_IWGRP | S_IWUSR);
  if (file == -1) {
      my_putstr("Cant't use file");
      return (1);
    }
  tmp = dup(1);
  dup2(file, 1);
  tab = my_str_to_wordtab(my_epur_str(com[1]), ' ', 0, 0);
  pid = fork();
  if (pid == 0)
    my_execve(char **param, env);
  else
    waitpid(0, &stat,0);
  close(file);
  dup2(tmp,1);
  return(0);
}
