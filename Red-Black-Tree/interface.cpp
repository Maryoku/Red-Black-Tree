#include "header.h"

void Delete(RB_trees *&tree, int key)
{
	RB_trees *pointer = tree;
	RB_trees *parent = NULL;

	while (pointer != NULL && pointer->key != key)
	{
		parent = pointer;
		if (key < pointer->key)
			pointer = pointer->left;
		else
			pointer = pointer->right;
	}

	if (pointer != NULL)
	{
		RB_trees *removed = NULL;

		if (pointer->left == NULL || pointer->right == NULL)
		{
			RB_trees *child = NULL;
			removed = pointer;

			if (pointer->left != NULL) {
				child = pointer->left;
			}
			else if (pointer->right != NULL) {
				child = pointer->right;
			}

			if (parent == NULL) {
				tree = child;
			}
			else
			{
				if (parent->left == pointer)
					parent->left = child;
				else
					parent->right = child;
			}
		}
		else // (pointer->left != NULL && pointer->right != NULL)
		{
			RB_trees *mostLeft = pointer->right;
			RB_trees *mostLeftParent = pointer;

			while (mostLeft->left != NULL)
			{
				mostLeftParent = mostLeft;
				mostLeft = mostLeft->left;
			}

			pointer->key = mostLeft->key;
			removed = mostLeft;

			if (mostLeftParent->left == mostLeft)
				mostLeftParent->left = NULL;
			else
				mostLeftParent->right = NULL;
		}

		cout << "element deleted" << endl << endl;
		delete removed;
	}
}

int FindPrev(RB_trees *tree, int key)
{
	RB_trees *current = tree;
	RB_trees *successor = NULL;
	while (current != NULL) {
		if (current->key < key) {
			successor = current;
			current = current->right;
		}
		else {
			current = current->left;
		}
	}

	return successor->key;
}

int FindNext(RB_trees *tree, int key)
{
	RB_trees *current = tree;
	RB_trees *successor = NULL;
	while (current != NULL) {
		if (current->key > key) {
			successor = current;
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	return successor->key;
}

int Find(RB_trees *tree, int key)
{
	while (tree) {
		if (key < tree->key) {
			tree = tree->left;
		}
		else if (key > tree->key) {
			tree = tree->right;
		}
		else if (key == tree->key)
			return tree->color;
	}
	return NULL;
}

void Add(RB_trees *&tree, int key, char color)
{
	if (tree == NULL) { // if node is empty (node == NULL)
		tree = new RB_trees;
		tree->key = key;
		tree->color = color;
		tree->left = tree->right = NULL;
	}

	else if (tree->key <= key) {
		Add(tree->right, key, color);
	}

	else if (tree->key > key) {
		Add(tree->left, key, color);
	}
}

void Print(RB_trees *&tree, int n)
{
	if (tree != NULL)
	{
		Print(tree->right, n + 5);
		for (int i = 0; i < n; i++) {
			printf(" ");
		}
		printf("%d%c\n", tree->key, tree->color);
		Print(tree->left, n + 5);
	}
}