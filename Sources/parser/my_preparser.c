/*
** my_preparser.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Tue May 13 19:39:15 2014 Zackary Beaugelin
<<<<<<< HEAD
** Last update Sat May 24 19:26:11 2014 jussea_m@epitech.eu
=======
** Last update Sun May 25 12:36:08 2014 Zackary Beaugelin
>>>>>>> 4405311b92607c9416d941b425e7949659f5b132
*/

#include "my_sh.h"

void	my_put_tok_err(char *tok)
{
  my_putstr(tok, 2);
  my_putstr(": token not yet supported\n", 2);
}

int	my_preparser2(char **cmd, char **tok, char **env, t_parse *p)
{
  int	ret;

  ret = 0;
  if (!my_strcmp(tok[p->i], "<"))
    my_lr(my_str_to_wordtab(my_epur_str(cmd[p->j]), ' ', 0, 0),
	  my_str_to_wordtab(cmd[p->j + 1], ' ', 0, 0), env);
  if (!my_strcmp(tok[p->i], "<<"))
    my_dlr(my_str_to_wordtab(my_epur_str(cmd[p->j]), ' ', 0, 0),
	   my_str_to_wordtab(cmd[p->j + 1], ' ', 0, 0), env);
  else if (!tok[p->i])
    ret = my_parser(my_str_to_wordtab(cmd[0], ' ', 0, 0), 1, env);
  else
    my_put_tok_err(tok[p->i]);
  p->j += 1;
  return (ret);
}

int		my_preparser(char **cmd, char **tok, char **env)
{
  t_parse	p;
  int		ret;

  p.j = -1;
  p.i = -1;
  if (!*tok && cmd)
    ret = my_parser(my_str_to_wordtab(cmd[0], ' ', 0, 0), 1, env);
  else if (cmd)
    while (tok[++p.i] && cmd[++p.j])
      if (!my_strcmp(tok[p.i], "&&") || !my_strcmp(tok[p.i], ";"))
	{
	  ret = my_parser(my_str_to_wordtab(my_epur_str(cmd[p.j]), ' ', 0, 0), 1, env);
	  if (!tok[p.i + 1])
	    ret = my_parser(my_str_to_wordtab(my_epur_str(cmd[p.j + 1]), ' ', 0, 0), 1, env);
	}
      else if (!my_strcmp(tok[p.i], ">"))
	my_rr(my_str_to_wordtab(my_epur_str(cmd[p.j]), ' ', 0, 0),
	      my_str_to_wordtab(cmd[p.j + 1], ' ', 0, 0), env);
      else if (!my_strcmp(tok[p.i], ">>"))
	my_drr(my_str_to_wordtab(my_epur_str(cmd[p.j]), ' ', 0, 0),
	       my_str_to_wordtab(cmd[p.j + 1], ' ', 0, 0), env);
      else
	ret = my_preparser2(cmd, tok, env, &p);
  return (ret);
}
