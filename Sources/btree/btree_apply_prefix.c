#include <stdlib.h>
#include "btree.h"
 
void	btree_apply_prefix(t_btree *root, int (*applyf)(void *))
{
	if (root->item != NULL)
		applyf(root->item);
	if (root->left != NULL)
		btree_apply_prefix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_prefix(root->right, applyf);
}