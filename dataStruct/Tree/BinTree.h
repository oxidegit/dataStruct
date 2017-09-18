#pragma once
#include "BinNode.h"

class BinTree {
public:
	BinTree() {
		root = NULL;
		root = createTree(root);
	};
	~BinTree() { destroyTree(root); };
	void preOrder() { preOrder(this->root); }
	void inOrder() { inOrder(this->root); };
	void postOrder() { postOrder(this->root); };
	void levelOrder() { levelOrder(this->root); };
private:
	BinNode* root;
	BinNode * createTree(BinNode *root);
	void destroyTree(BinNode *root);
	void preOrder(BinNode* root);
	void inOrder(BinNode *root);
	void postOrder(BinNode *root);
	void levelOrder(BinNode *root);
};