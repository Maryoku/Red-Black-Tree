#include "header.h"

int array_color[100];
int length_array_col = 0;

void Coloring(RB_trees *tree, int h)
{
	if (!tree)
	{
		array_color[length_array_col] = h;
		length_array_col++;
		return;
	}

	Coloring(tree->left, h + 1);
	Coloring(tree->right, h + 1);
}

void result_coloring()
{
	int max = 0, min = array_color[1];
	for (int j = 0; j < length_array_col - 1; j++)
	{
		if (array_color[j] > max)
			max = array_color[j];
		if (array_color[j] < min)
			min = array_color[j];
	}

	if (max <= 2 * min) {
		printf("Coloring is possible\n\n");
	}
	else {
		printf("Coloring is impossible\n");
	}
}