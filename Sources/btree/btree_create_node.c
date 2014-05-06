#include <stdlib.h>
#include "btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree       *node;
 
	node = malloc(sizeof(t_btree));
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}