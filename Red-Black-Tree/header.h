#include "stdio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

struct RB_trees
{
	int key;
	char color; //r or b
	RB_trees *left, *right;
};

void Add(RB_trees *&tree, int key, char color);
void Delete(RB_trees *&tree, int key);
int Find(RB_trees *tree, int key);
int FindNext(RB_trees *tree, int key);
int FindPrev(RB_trees *tree, int key);
void Print(RB_trees *&tree, int n);

void Menu(RB_trees *&tree);

void Check_RB(RB_trees *tree, int h);
void Coloring(RB_trees *tree, int h);
void result_check();
void result_coloring();
