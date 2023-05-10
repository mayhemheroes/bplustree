#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bplustree.h"

int LLVMFuzzerTestOneInput(char * data, size_t size)
{
	struct bplus_tree * tree = NULL;
	tree = bplus_tree_init("data.index", 4096);
	if(size > 4)
		bplus_tree_put(tree, ((key_t *)data)[0], ((long *) data)[sizeof(int)]);
	bplus_tree_deinit(tree);
	return 0;
}
