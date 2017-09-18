#include <iostream>
#include "BinTree.h"

using namespace std;

BinNode * BinTree::createTree(BinNode *root) {
	char c;
	cin >> c;

	if (c != '#') {
		root = new BinNode();
		root->value = c;
		root->leftChild = createTree(root->leftChild);
		root->rightChild = createTree(root->rightChild);
	}

	return root;
}
void BinTree::destroyTree(BinNode *root) {
	if (root) {
		destroyTree(root->leftChild);
		destroyTree(root->rightChild);
		delete root;
	}
}
void BinTree::preOrder(BinNode* root) {
	if (root) {
		cout << root->value << " ";
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}
void BinTree::inOrder(BinNode *root) {
	if (root) {
		preOrder(root->leftChild);
		cout << root->value << " ";
		preOrder(root->rightChild);
	}
}
void BinTree::postOrder(BinNode *root) {
	if (root) {
		preOrder(root->leftChild);
		preOrder(root->rightChild);
		cout << root->value << " ";
	}
}
void BinTree::levelOrder(BinNode *root) {
	BinNode *pQueue[20];
	BinNode *current = NULL;
	int front = -1;
	int rear = -1;

	if (root) {
		pQueue[++rear] = root;
	}
	while (rear != front) {
		current = pQueue[++front];
		cout << current->value << " ";

		if (current->leftChild) {
			pQueue[++rear] = current->leftChild;
		}
		if (current->rightChild) {
			pQueue[++rear] = current->rightChild;
		}
	}
}