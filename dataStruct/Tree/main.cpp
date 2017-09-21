#include <iostream>
#include "BinTree.h"

using namespace std;

int main() {

	BinTree t = BinTree();
	t.preOrder();
	cout << endl;
	t.preOrderLoop();
	cout << endl;
	t.inOrder();
	cout << endl;
	t.inOrderLoop();
	cout << endl;
	t.postOrder();
	cout << endl;
	t.postOrderLoop();
	cout << endl;
	t.levelOrder();

	return 0;
}