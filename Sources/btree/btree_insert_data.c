#include <stdlib.h>
#include "btree.h"
 
void	btree_insert_data(t_btree **root, void *item,
							 int (*cmpf)(void *, void *));
 
 t_btree	*btree_create_node(void *item)
{
	t_btree		*node;
 
	node = malloc(sizeof(t_btree));
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

void	btree_insert_data(t_btree **root, void *item,
							 int (*cmpf)(void *, void *))
{
	t_btree		*node;
 
	node = btree_create_node(item);
	if (root != NULL)
	{      
		if (cmpf((*root)->item, item) > 0)
			if ((*root)->left == NULL)
				(*root)->left = node;
			else
				btree_insert_data(&(*root)->left, item, cmpf);
		else
			if ((*root)->right == NULL)
				(*root)->right = node;
			else
				btree_insert_data(&(*root)->right, item, cmpf);
    }
}