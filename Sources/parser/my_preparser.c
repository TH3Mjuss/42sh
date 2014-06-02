/*
** my_preparser.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Tue May 13 19:39:15 2014 Zackary Beaugelin
** Last update Mon Jun  2 13:58:40 2014 Zackary Beaugelin
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
    my_lr(my_str_to_wordtab(CMD(cmd[p->j])),
	  my_str_to_wordtab(CMD(cmd[p->j + 1])), env);
  else if (!my_strcmp(tok[p->i], "<<"))
    my_dlr(my_str_to_wordtab(CMD(cmd[p->j])),
	   my_str_to_wordtab(CMD(cmd[p->j + 1])), env);
  else if (!my_strcmp(tok[p->i], "&&"))
    {
      if (!(ret = my_parser(my_str_to_wordtab(CMD(cmd[p->j])), 1, env)))
	ret = my_parser(my_str_to_wordtab(CMD(cmd[p->j + 1])), 1, env);
    }
  else if (!my_strcmp(tok[p->i], "||"))
    {
      if ((ret = my_parser(my_str_to_wordtab(CMD(cmd[p->j])), 1, env)))
	ret = my_parser(my_str_to_wordtab(CMD(cmd[p->j + 1])), 1, env);
    }
  else if (!tok[p->i])
    ret = my_parser(my_str_to_wordtab(CMD(cmd[0])), 1, env);
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
  ret = 0;
  if (!*tok && cmd)
    ret = my_parser(my_str_to_wordtab(CMD(cmd[0])), 1, env);
  else if (cmd)
    while (tok[++p.i] && cmd[++p.j])
      if (!my_strcmp(tok[p.i], ";"))
	{
	  ret = my_parser(my_str_to_wordtab(CMD(cmd[p.j])), 1, env);
	  if (!tok[p.i + 1])
	    ret = my_parser(my_str_to_wordtab(CMD(cmd[p.j + 1])), 1, env);
	}
      else if (!my_strcmp(tok[p.i], ">"))
	my_rr(my_str_to_wordtab(CMD(cmd[p.j])),
	      my_str_to_wordtab(CMD(cmd[p.j + 1])), env);
      else if (!my_strcmp(tok[p.i], ">>"))
	my_drr(my_str_to_wordtab(CMD(cmd[p.j])),
	       my_str_to_wordtab(CMD(cmd[p.j + 1])), env);
      else
	ret = my_preparser2(cmd, tok, env, &p);
  return (ret);
}
