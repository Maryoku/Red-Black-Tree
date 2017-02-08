#include "header.h"

int i = 0;
int array_check[100];

void Check_RB(RB_trees *tree, int h)
{
	if (!tree)
	{
		array_check[i] = h;
		i++;
		return;
	}

	if (tree->color == 'b') {
		h++;
	}
	else {
		if ((tree->right) && (tree->left)) {
			if ((tree->right->color == 'r') && (tree->left->color == 'r')) {
				array_check[i] = 0;
				i++;
			}
		}
	}
		
	Check_RB(tree->left, h);
	Check_RB(tree->right, h);
}

void result_check()
{
	bool rb = 1;
	for (int j = 0; j < i - 1; j++) {
		if (array_check[j] != array_check[j + 1]) {
			rb = 0;
			break;
		}
	}

	if (rb) {
		printf("Tree is red-black\n");
	}
	else {
		printf("Tree is not red-black\n");
	}
}