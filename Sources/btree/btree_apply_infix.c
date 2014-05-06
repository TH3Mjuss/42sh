#include <stdlib.h>
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