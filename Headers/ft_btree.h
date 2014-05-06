/*
** ft_btree.h for 42sh in /home/gysc0/rendu/my_42
**
** Made by Gysc0
** Login   <gysc0@epitech.net>
**
** Started on  Tue May  6 16:23:19 2014 Gysc0
** Last update Tue May  6 16:27:27 2014 Gysc0
*/

#ifndef	__FT_BTREE_H__
# define __FT_BTREE_H__

typedef struct		s_btree
{
 struct s_btree		*left;
 struct s_btree		*right;
 void			*item;
}			t_btree;

t_btree	*btree_create_node(void *item);
void	btree_insert_data(t_btree **root, void *item,
			    int (*cmpf)(void *, void *));
void	btree_apply_prefix(t_btree *root, int (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, int (*applyf)(void *));
void	btree_apply_infix(t_btree *root, int (*applyf)(void *));

#endif /*__FT_BTREE_H__*/
