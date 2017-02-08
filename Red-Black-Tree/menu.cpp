#include "header.h"

void Menu(RB_trees *&tree)
{
	int key, choose;
	char color;

	cout << "Choose operation: \n1 - Add \n2 - Delete \n3 - Find \n4 - Find Next \n5 - Find Prev \n6 - Print tree \n7 - Exit\n\n";
	cin >> choose;

	if (choose < 6) {
		cout << "Print key: \n";
		cin >> key;
	}

	switch (choose) {
	case 1:
		cout << "Print color: ";
		cin >> color;
		Add(tree, key, color);
		Print(tree, 0);
		Menu(tree);
		break;
	case 2:
		Delete(tree, key);
		Print(tree, 0);
		Menu(tree);
		break;
	case 3:
		printf("%c\n", Find(tree, key));
		Menu(tree);
		break;
	case 4:
		printf("%d\n", FindNext(tree, key));
		Menu(tree);
		break;
	case 5:
		printf("%d\n", FindPrev(tree, key));
		Menu(tree);
		break;
	case 6:
		Print(tree, 0);
		Menu(tree);
		break;
	case 7:
		return;
		break;
	}
}