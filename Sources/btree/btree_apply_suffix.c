#include <stdlib.h>
#include "btree.h"
 
void	btree_apply_suffix(t_btree *root, int (*applyf)(void *))
{
	if (root->left != NULL)
		btree_apply_suffix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_suffix(root->right, applyf);
	if (root->item != NULL)
		applyf(root->item);
}