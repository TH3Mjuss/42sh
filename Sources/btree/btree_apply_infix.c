/*
** btree_apply_infix.c for 42sh in /home/gysc0/rendu/my_42
**
** Made by Gysc0
** Login   <gysc0@epitech.net>
**
** Started on  Tue May  6 16:18:17 2014 Gysc0
** Last update Tue May  6 16:28:13 2014 Gysc0
*/

#include "my_sh.h"
#include "btree.h"

void	btree_apply_infix(t_btree *root, int (*applyf)(void *))
{
  if (root->left != NULL)
    btree_apply_infix(root->left, applyf);
  if (root->item != NULL)
    applyf(root->item);
  if (root->right != NULL)
    btree_apply_infix(root->right, applyf);
}
